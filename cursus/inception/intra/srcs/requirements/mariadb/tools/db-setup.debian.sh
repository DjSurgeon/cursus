#!/bin/bash

set -e
# If any command fails, the script stops immediately
# This prevents the script from continuing in an inconsistent state
# For example: if DB creation fails, we don't try to start MariaDB

# ── Read credentials from secrets ────────────────────────────────────────────
# Secrets are mounted as files in /run/secrets/
# NOT as environment variables — that would be less secure
DB_PASSWORD=$(cat /run/secrets/db_password)
DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)

# ── Initialization — only the first time ─────────────────────────────────────
# Check if the mysql directory exists inside the datadir
# If it doesn't, it's the first time the container starts
# If it exists, it's already initialized and we skip all setup
if [ ! -d "/var/lib/mysql/mysql" ]; then

    echo "First run — initializing MariaDB..."

    # Initialize the directory structure and system files of MariaDB
    # --user=mysql: run as the mysql user, not as root
    # --datadir: where to store data (matches my.cnf and the volume)
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql

    # Start MariaDB temporarily in the background so we can configure it
    # --skip-networking: do not accept external connections during setup
    # --user=mysql: run as the mysql user
    mysqld --user=mysql --skip-networking &
    MYSQL_PID=$!
    # Save the PID so we can kill it after setup

    # Wait until MariaDB is ready to accept connections
    # mysqladmin ping returns 0 when the server responds
    echo "Waiting for MariaDB to be ready..."
    until mysqladmin ping --silent 2>/dev/null; do
        sleep 1
    done
    echo "MariaDB ready"

    # Execute the configuration SQL using the mysql client
    # This is where we create the DB, users, and permissions
    mysql --user=root << EOF
-- Force a privilege reload before making changes
FLUSH PRIVILEGES;

-- Change the root password
-- IDENTIFIED BY: sets the password
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';

-- Create the WordPress database if it doesn't exist
-- IF NOT EXISTS: avoids an error if it already exists (for safety)
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};

-- Create the user that WordPress will use to connect
-- '%' means "from any host" — necessary because WordPress
-- is in another container with a dynamic IP
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';

-- Grant all privileges on the WordPress DB to that user
-- Only on wordpress.* — not on other databases
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';

-- Apply privilege changes immediately
FLUSH PRIVILEGES;
EOF

    # Stop the temporary instance cleanly
    # Send SIGTERM to the process we saved earlier
    kill $MYSQL_PID
    wait $MYSQL_PID
    # wait: waits for the process to fully terminate
    # Without this, we might start the final instance before
    # the temporary one has completely shut down

    echo "MariaDB initialized successfully"
fi

# ── Start MariaDB in foreground as PID 1 ─────────────────────────────────────
# exec replaces the current process (bash) with mysqld
# This makes mysqld PID 1 — not a child of the script
# Docker can then send signals directly to it (SIGTERM to stop)
# Without exec: bash would be PID 1 and mysqld a child process — Docker couldn't
# communicate with it properly
exec mysqld --user=mysql