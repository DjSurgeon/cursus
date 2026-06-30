#!/bin/sh

# Generate the SSL certificate dynamically using $DOMAIN_NAME
openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -out /etc/nginx/ssl/inception.crt \
    -keyout /etc/nginx/ssl/inception.key \
    -subj "/C=ES/ST=Madrid/L=Madrid/O=42/OU=42/CN=${DOMAIN_NAME}"

# Replace the domain name placeholder in nginx.conf dynamically
sed -i "s/DOMAIN_NAME_PLACEHOLDER/${DOMAIN_NAME}/g" /etc/nginx/nginx.conf

# Execute the CMD passed as arguments
exec "$@"
