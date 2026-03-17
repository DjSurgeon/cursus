#!/bin/sh
set -e

# 1. Leer secretos
DB_PASSWORD=$(cat /run/secrets/db_password)
# Suponiendo que en credentials.txt tienes "ADMIN_PASS=tuclave" y "WP_USER_PASS=otra"
ADMIN_PASSWORD=$(grep ADMIN_PASS /run/secrets/credentials.txt | cut -d '=' -f2)
USER_PASSWORD=$(grep WP_USER_PASS /run/secrets/credentials.txt | cut -d '=' -f2)

# 2. Bucle de espera: WordPress no puede instalarse si la base de datos no está lista
echo "Esperando a que MariaDB esté lista..."
while ! mariadb -h mariadb -u ${MYSQL_USER} -p${DB_PASSWORD} ${MYSQL_DATABASE} -e "SELECT 1;" >/dev/null 2>&1; do
    sleep 2
    echo "Reintentando conexión a MariaDB..."
done
echo "¡MariaDB está lista!"

# 3. Instalación de WordPress usando WP-CLI
# Si wp-config.php no existe, significa que el volumen está vacío y hay que instalar
if [ ! -f /var/www/html/wp-config.php ]; then
    echo "Descargando e instalando WordPress..."
    
    # Descargar archivos base de WordPress
    wp core download --allow-root

    # Crear el archivo de configuración con los datos de MariaDB
    wp config create \
        --dbname=${MYSQL_DATABASE} \
        --dbuser=${MYSQL_USER} \
        --dbpass=${DB_PASSWORD} \
        --dbhost=mariadb \
        --allow-root

    # Instalar WordPress (crea las tablas en la base de datos)
    # NOTA: Asegúrate de que $DOMAIN_NAME, $WP_ADMIN_USER, etc., estén en tu .env
    wp core install \
        --url=https://${DOMAIN_NAME} \
        --title="Inception 42" \
        --admin_user=${WP_ADMIN_USER} \
        --admin_password=${ADMIN_PASSWORD} \
        --admin_email=${WP_ADMIN_EMAIL} \
        --allow-root

    # Crear el segundo usuario (Requisito estricto del subject)
    wp user create \
        ${WP_USER} ${WP_USER_EMAIL} \
        --role=author \
        --user_pass=${USER_PASSWORD} \
        --allow-root

    echo "WordPress instalado y configurado con éxito."
else
    echo "WordPress ya está instalado."
fi

# 4. Arrancar PHP-FPM en primer plano (FOREGROUND) para que sea el PID 1
# El flag -F es obligatorio. Si no lo pones, PHP se va a background y el contenedor muere.
exec php-fpm82 -F