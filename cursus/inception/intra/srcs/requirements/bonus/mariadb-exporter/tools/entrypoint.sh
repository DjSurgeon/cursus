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

# Export connection string locally, so it is never exposed in docker-compose.yml
export DATA_SOURCE_NAME="exporter:${EXPORTER_PASSWORD}@(mariadb:3306)/"

echo "Starting mysqld_exporter..."

# Execute mysqld_exporter as PID 1
exec /usr/local/bin/mysqld_exporter
