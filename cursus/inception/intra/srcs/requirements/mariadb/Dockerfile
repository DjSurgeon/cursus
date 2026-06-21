# Base image: Uses the penultimate stable version of Alpine Linux.
FROM alpine:3.22

# Install required dependencies.
# The --no-cache flag prevents storing the package index, keeping the image size minimal.
RUN apk add --no-cache mariadb mariadb-client

# Copy custom configuration file to allow remote connections.
COPY conf/my.cnf /etc/my.cnf.d/mariadb-server.cnf

# Copy the initialization script.
COPY tools/db-setup.sh /usr/local/bin/db-setup.sh

# Grant execution permissions to the script.
RUN chmod +x /usr/local/bin/db-setup.sh

# Expose the standard MariaDB port.
EXPOSE 3306

# Define the entrypoint to handle container lifecycle.
# The script will eventually execute MariaDB as PID 1.
ENTRYPOINT ["/usr/local/bin/db-setup.sh"]