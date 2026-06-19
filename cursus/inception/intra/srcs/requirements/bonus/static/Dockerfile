# Base image
FROM alpine:3.22

# Install lighttpd
RUN apk update && apk upgrade && \
    apk add --no-cache lighttpd

# Create directory structure for the web server
RUN mkdir -p /var/www/localhost/htdocs

# Copy configuration and web files
COPY conf/lighttpd.conf /etc/lighttpd/lighttpd.conf
COPY tools/index.html /var/www/localhost/htdocs/index.html
COPY tools/style.css /var/www/localhost/htdocs/style.css

# Assign ownership to lighttpd user
RUN chown -R lighttpd:lighttpd /var/www/localhost/htdocs

# Expose the configured port
EXPOSE 1337

# Start lighttpd in foreground
ENTRYPOINT ["lighttpd", "-D", "-f", "/etc/lighttpd/lighttpd.conf"]
