# Base image: Uses the penultimate stable version of Alpine Linux.
FROM alpine:3.22

# Install NGINX and OpenSSL.
# The --no-cache flag prevents storing the package index, keeping the image size minimal.
RUN apk update && apk add --no-cache nginx openssl

# Create the directory for storing SSL/TLS certificates.
RUN mkdir -p /etc/nginx/ssl

# Generate a self-signed SSL certificate for HTTPS encryption.
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -out /etc/nginx/ssl/inception.crt \
    -keyout /etc/nginx/ssl/inception.key \
    -subj "/C=ES/ST=Madrid/L=Madrid/O=42/OU=42/CN=serjimen.42.fr"

# Copy the custom NGINX configuration file.
COPY conf/nginx.conf /etc/nginx/nginx.conf

# Expose ONLY port 443 as per the subject requirements.
EXPOSE 443

# Start NGINX in the foreground to run as PID 1.
CMD ["nginx", "-g", "daemon off;"]