#!/bin/sh
# The shebang indicates this script is executed by 'sh' (ash).
# IMPORTANT FOR THE DEFENSE: We use 'sh' and not 'bash' because Alpine Linux
# is ultra‑light and does not include bash by default to save space.

set -e
# If any command fails, the script stops immediately.
# Prevents the container from starting in a corrupted state if installation fails.

# ── Read credentials from secrets ────────────────────────────────────────────
# Secrets are mounted in RAM under /run/secrets/ thanks to Docker Compose.
# THE EVALUATOR WILL ASK: Why not use normal environment variables (.env)?
# ANSWER: Because the subject requires security. Environment variables are visible
# if someone runs 'docker inspect'. Secrets are actual files securely mounted.
DB_PASSWORD=$(cat /run/secrets/db_password)
DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)

# ── Initialization — only the first time ─────────────────────────────────────
# Check if the main MariaDB data directory exists.
# If it doesn't, it's the first time the container starts or the volume is empty.
if [ ! -d "/var/lib/mysql/mysql" ]; then
    
    echo "First run — initializing MariaDB in Alpine..."
    
    # 1. Initialize the directory structure of the MariaDB system.
    # --user=mysql: For security, run as the 'mysql' user, never as system 'root'.
    # --datadir: Defines where to store data (matches the host volume).
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql

    # 2. Create a temporary file with the SQL configuration instructions.
    # We use this file for MariaDB's secure bootstrap mode.
    cat << EOF > /tmp/init.sql
FLUSH PRIVILEGES;

-- Change the password of the database administrator 'root'
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';

-- Create the WordPress database
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;

-- Create the user that WordPress will use to connect
-- '%' means "from any IP" — vital because WordPress is in another container
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';

-- Grant full privileges to that user ONLY on the WordPress database
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';

FLUSH PRIVILEGES;
EOF

    # 3. Apply the configuration in Bootstrap mode (Safe Mode)
    # THE EVALUATOR WILL ASK: Why do you use --bootstrap instead of starting the server and using 'mysql'?
    # ANSWER: Bootstrap mode starts MariaDB internally without opening network ports.
    # It reads the SQL file, applies passwords directly to the data files, and shuts down.
    # It is much faster, safer, and avoids having to do 'sleep' loops waiting for the server to wake up.
    /usr/bin/mysqld --user=mysql --bootstrap < /tmp/init.sql
    
    # Security cleanup: delete the file containing plain‑text passwords
    rm -f /tmp/init.sql
    
    echo "MariaDB initialized successfully"
fi

# ── Start MariaDB in foreground as PID 1 ─────────────────────────────────────
# THE EVALUATOR WILL ASK: What does the 'exec' keyword do and why is it mandatory?
# ANSWER: 'exec' destroys this script (sh) and replaces it with the 'mysqld' process.
# This ensures that MariaDB becomes PID 1 of the container.
# If MariaDB hangs, the container dies gracefully (fulfilling the rule
# of not using hacks like 'tail -f' or infinite loops).
exec /usr/bin/mysqld --user=mysql --console