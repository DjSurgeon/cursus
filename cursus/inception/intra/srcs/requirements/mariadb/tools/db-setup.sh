#!/bin/sh

# Note for the evaluation: We use 'sh' instead of 'bash' because Alpine Linux
# is lightweight and does not include bash by default.

# Stop script execution immediately if any command fails.
# This prevents the container from starting in a corrupted state.
set -e

# --- Color Definitions ---
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m'

# --- Directory Setup ---
# Create the socket directory required by MariaDB to create mysqld.sock.
# This directory is not present by default in the Alpine base image.
mkdir -p /run/mysqld
chown mysql:mysql /run/mysqld

# --- Credential Loading ---
# Read database credentials securely from Docker secrets mounted in RAM.
if [ -f /run/secrets/db_password ] && [ -f /run/secrets/db_root_password ] && [ -f /run/secrets/mariadb_exporter_pwd ]; then
    DB_PASSWORD=$(cat /run/secrets/db_password)
    DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)
    EXPORTER_PASSWORD=$(cat /run/secrets/mariadb_exporter_pwd)
else
    echo -e "${RED}Error: Secrets files not found in /run/secrets/${NC}"
    exit 1
fi

# --- Database Initialization ---
# Check if the system database directory exists to determine if this is the first run.
if [ ! -d "/var/lib/mysql/mysql" ]; then

    echo -e "${BLUE}First run detected. Initializing MariaDB...${NC}"

    # Initialize MariaDB system tables.
    # The --skip-test-db flag avoids installing unnecessary test databases.
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql --skip-test-db

    # Generate the SQL script for initial configuration.
    # Backticks are used around the database name to safely handle reserved words.
    cat << EOF > /tmp/init.sql
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
CREATE USER IF NOT EXISTS 'exporter'@'%' IDENTIFIED BY '${EXPORTER_PASSWORD}';
GRANT PROCESS, REPLICATION CLIENT, SLAVE MONITOR, SELECT ON *.* TO 'exporter'@'%';
FLUSH PRIVILEGES;
EOF

    # Start a temporary MariaDB instance without networking for local configuration.
    mysqld --user=mysql --skip-networking &
    MYSQL_PID=$!

    # Wait until the temporary MariaDB instance is ready to accept local connections.
    echo -e "${BLUE}Waiting for MariaDB to initialize...${NC}"
    until mysqladmin ping --silent 2>/dev/null; do
        sleep 1
    done
    echo -e "${GREEN}MariaDB is ready for configuration.${NC}"

    # Apply the SQL configuration script.
    mysql --user=root < /tmp/init.sql

    # Clean up the temporary SQL script for security.
    rm -f /tmp/init.sql

    # Stop the temporary MariaDB instance gracefully.
    kill $MYSQL_PID
    wait $MYSQL_PID

    echo -e "${GREEN}MariaDB initialization completed successfully.${NC}"
fi

# --- Start Main Process ---
# Execute the MariaDB daemon in the foreground.
# Using 'exec' replaces the shell process with mysqld, making it PID 1.
# This ensures proper signal handling and avoids infinite sleep hacks.
echo -e "${BLUE}Starting MariaDB service...${NC}"
exec /usr/bin/mysqld --user=mysql
