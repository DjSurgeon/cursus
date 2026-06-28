# Base image: Uses the penultimate stable version of Alpine Linux.
FROM alpine:3.22

# Install required dependencies.
# The --no-cache flag prevents storing the package index, keeping the image size minimal.
RUN apk update && apk add --no-cache \
    php82 \
    php82-fpm \
    php82-mysqli \
    php82-curl \
    php82-dom \
    php82-exif \
    php82-fileinfo \
    php82-mbstring \
    php82-openssl \
    php82-xml \
    php82-zip \
    php82-phar \
    php82-tokenizer \
    php82-ctype \
    php82-session \
    php82-pecl-redis \
    wget \
    mariadb-client

# Create a symbolic link for PHP to allow using 'php' instead of 'php82'.
RUN ln -s /usr/bin/php82 /usr/bin/php

# Install WP-CLI (Official tool to manage WordPress from the command line).
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

# Copy PHP-FPM configuration and the setup script.
COPY conf/www.conf /etc/php82/php-fpm.d/www.conf
COPY tools/wp-setup.sh /usr/local/bin/wp-setup.sh

# Grant execution permissions to the script.
RUN chmod +x /usr/local/bin/wp-setup.sh

# Create the web root directory and set it as the working directory.
RUN mkdir -p /var/www/html
WORKDIR /var/www/html

# Expose the port where PHP-FPM will listen for NGINX requests.
EXPOSE 9000

# Define the entrypoint to handle container lifecycle.
# The script will execute PHP-FPM as PID 1.
ENTRYPOINT ["/usr/local/bin/wp-setup.sh"]