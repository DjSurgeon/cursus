#!/bin/bash

set -e
# Stop immediately if any command fails
# Critical here — if DB connection fails we don't want a broken WordPress

# ── Read credentials from secrets ────────────────────────────────────────────
# Passwords are mounted as files in /run/secrets/
# Never passed as environment variables — more secure
DB_PASSWORD=$(cat /run/secrets/db_password)
WP_ADMIN_PASSWORD=$(grep ADMIN_PASS /run/secrets/credentials | cut -d= -f2)
WP_USER_PASSWORD=$(grep WP_USER_PASS /run/secrets/credentials | cut -d= -f2)

# ── Wait for MariaDB to be ready ──────────────────────────────────────────────
# WordPress container might start before MariaDB is ready
# We loop until MariaDB accepts connections
# This replaces the need for depends_on with health checks
echo "Waiting for MariaDB to be ready..."
until wp db check \
    --dbhost=mariadb \
    --dbname=${MYSQL_DATABASE} \
    --dbuser=${MYSQL_USER} \
    --dbpass=${DB_PASSWORD} \
    --allow-root 2>/dev/null; do
    sleep 2
done
echo "MariaDB is ready"

# ── Install WordPress — only the first time ───────────────────────────────────
# wp-config.php only exists after a successful install
# If it doesn't exist, this is the first run
if [ ! -f /var/www/html/wp-config.php ]; then

    echo "First run — installing WordPress..."

    # Download WordPress core files into /var/www/html
    # --allow-root: WP-CLI warns about running as root, this suppresses it
    wp core download --allow-root

    # Create wp-config.php with database connection details
    # --dbhost=mariadb: "mariadb" is the service name in the Docker network
    # Docker resolves this name to the MariaDB container's IP automatically
    wp config create \
        --dbname=${MYSQL_DATABASE} \
        --dbuser=${MYSQL_USER} \
        --dbpass=${DB_PASSWORD} \
        --dbhost=mariadb \
        --allow-root

    # Install WordPress — creates all tables in the database
    # and sets up the site with admin user
    wp core install \
        --url=https://${DOMAIN_NAME} \
        --title="Inception" \
        --admin_user=${WP_ADMIN_USER} \
        --admin_password=${WP_ADMIN_PASSWORD} \
        --admin_email=${WP_ADMIN_EMAIL} \
        --skip-email \
        --allow-root

    # Create the second user — required by the subject
    # role=author: can write posts but not manage the site
    # The subject requires 2 users: one admin + one normal user
    wp user create \
        ${WP_USER} ${WP_USER_EMAIL} \
        --role=author \
        --user_pass=${WP_USER_PASSWORD} \
        --allow-root

    echo "WordPress installed successfully"
fi

# ── Start php-fpm in foreground as PID 1 ─────────────────────────────────────
# -F flag = foreground mode (no daemon)
# Without -F, php-fpm backgrounds itself and the container dies immediately
# exec replaces this script with php-fpm, making it PID 1
exec php-fpm8.2 -F