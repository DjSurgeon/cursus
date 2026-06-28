#!/bin/sh

# Stop script execution immediately if any command fails.
set -e

# --- Credential Loading ---
# Read database credentials securely from Docker secrets.
DB_PASSWORD=$(cat /run/secrets/db_password)
ADMIN_PASSWORD=$(grep ADMIN_PASS /run/secrets/credentials | cut -d '=' -f2)
USER_PASSWORD=$(grep WP_USER_PASS /run/secrets/credentials | cut -d '=' -f2)

# --- Database Connection Wait ---
# WordPress requires the database to be ready before installation.
# This loop checks the connection to MariaDB continuously.
echo "Waiting for MariaDB to be ready..."
while ! mariadb -h mariadb -u ${MYSQL_USER} -p${DB_PASSWORD} ${MYSQL_DATABASE} -e "SELECT 1;" >/dev/null 2>&1; do
    sleep 8
    echo "Retrying connection to MariaDB..."
done
echo "MariaDB is ready."

# --- WordPress Installation ---
# Check if wp-config.php exists. If not, the volume is empty and requires installation.
if [ ! -f /var/www/html/wp-config.php ]; then
    echo "Downloading and installing WordPress..."
    
    # Download WordPress core files.
    php -d memory_limit=512M /usr/local/bin/wp core download --allow-root

    # Create the configuration file with MariaDB credentials.
    wp config create \
        --dbname=${MYSQL_DATABASE} \
        --dbuser=${MYSQL_USER} \
        --dbpass=${DB_PASSWORD} \
        --dbhost=mariadb \
        --allow-root

    # Execute WordPress core installation to initialize database tables.
    wp core install \
        --url=https://${DOMAIN_NAME} \
        --title="Inception 42" \
        --admin_user=${WP_ADMIN_USER} \
        --admin_password=${ADMIN_PASSWORD} \
        --admin_email=${WP_ADMIN_EMAIL} \
        --allow-root

    # Create the second user.
    wp user create \
        ${WP_USER} ${WP_USER_EMAIL} \
        --role=author \
        --user_pass=${USER_PASSWORD} \
        --allow-root

    # --- Redis Cache Setup (Bonus) ---
    echo "Configuring Redis Object Cache..."
    
    # Append Redis connection constants to wp-config.php.
    wp config set WP_REDIS_HOST redis --allow-root
    wp config set WP_REDIS_PORT 6379 --raw --allow-root

    # Install and activate the Redis cache plugin.
    wp plugin install redis-cache --activate --allow-root
    
    # Enable the Object Cache functionality.
    wp redis enable --allow-root

    echo "WordPress installed and configured successfully."
else
    echo "WordPress is already installed."
fi

# --- Start Main Process ---
# Execute PHP-FPM in the foreground to make it PID 1.
# The -F flag is mandatory; otherwise, PHP goes to the background and the container exits.
echo "Setting permissions for nobody user..."
chown -R nobody:nobody /var/www/html

exec php-fpm82 -F