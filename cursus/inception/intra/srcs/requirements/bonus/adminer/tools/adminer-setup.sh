#!/bin/sh

# Download Adminer if it doesn't exist
if [ ! -f "/var/www/html/index.php" ]; then
    echo "Downloading Adminer..."
    # Descarga la versión oficial en un solo archivo
    wget https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php -O /var/www/html/index.php
    
    # Asignamos permisos correctos
    chown -R root:root /var/www/html
    chmod 755 /var/www/html/index.php
    echo "Adminer installed."
fi

# Iniciar servidor web de PHP embebido en primer plano (PID 1)
# Apuntamos a la carpeta donde descargamos el index.php
echo "Starting PHP built-in web server for Adminer..."
exec php82 -S 0.0.0.0:8080 -t /var/www/html
