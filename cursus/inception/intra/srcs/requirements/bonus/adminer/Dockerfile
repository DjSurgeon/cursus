# Base image
FROM alpine:3.22

# Install PHP and extensions for MariaDB connection
RUN apk update && apk upgrade && \
    apk add --no-cache php82 php82-session php82-mysqli php82-pdo php82-pdo_mysql wget

# Create directory for Adminer
RUN mkdir -p /var/www/html

# Copy the setup script
COPY tools/adminer-setup.sh /usr/local/bin/adminer-setup.sh
RUN chmod +x /usr/local/bin/adminer-setup.sh

# Expose internal port for PHP web server
EXPOSE 8080

# Execute setup script
ENTRYPOINT ["/usr/local/bin/adminer-setup.sh"]
