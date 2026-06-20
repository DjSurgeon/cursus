#!/bin/sh

set -e

# Wait a few seconds to ensure MariaDB is up before exporter tries to connect
echo "Waiting 5 seconds for MariaDB to initialize..."
sleep 5

# Read password from secrets (Docker Secrets rule)
if [ -f /run/secrets/mariadb_exporter_pwd ]; then
    EXPORTER_PASSWORD=$(cat /run/secrets/mariadb_exporter_pwd)
else
    echo "Error: Secret file /run/secrets/mariadb_exporter_pwd not found."
    exit 1
fi

# Create .my.cnf file for mysqld_exporter (v0.15.1+ requires this instead of DATA_SOURCE_NAME)
cat << EOF > /.my.cnf
[client]
user=exporter
password=${EXPORTER_PASSWORD}
host=mariadb
port=3306
EOF

echo "Starting mysqld_exporter..."

# Execute mysqld_exporter as PID 1
exec /usr/local/bin/mysqld_exporter --config.my-cnf="/.my.cnf"
