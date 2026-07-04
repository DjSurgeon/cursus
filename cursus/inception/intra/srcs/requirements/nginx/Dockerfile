# Base image: Uses the penultimate stable version of Alpine Linux.
FROM alpine:3.22

# Install NGINX and OpenSSL.
# The --no-cache flag prevents storing the package index, keeping the image size minimal.
RUN apk update && apk add --no-cache nginx openssl

# Create the directory for storing SSL/TLS certificates.
RUN mkdir -p /etc/nginx/ssl

# Copy the custom NGINX configuration file.
COPY conf/nginx.conf /etc/nginx/nginx.conf

# Copy the entrypoint script
COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

# Expose ONLY port 443 as per the subject requirements.
EXPOSE 443

# Set the entrypoint to generate certificates dynamically
ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]

# Start NGINX in the foreground to run as PID 1.
CMD ["nginx", "-g", "daemon off;"]