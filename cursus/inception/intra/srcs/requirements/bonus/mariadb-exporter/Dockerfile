# Base image
FROM alpine:3.22

# Install dependencies
RUN apk add --no-cache wget tar ca-certificates

# Download and extract mysqld_exporter
RUN wget https://github.com/prometheus/mysqld_exporter/releases/download/v0.15.1/mysqld_exporter-0.15.1.linux-amd64.tar.gz && \
    tar -xvzf mysqld_exporter-0.15.1.linux-amd64.tar.gz && \
    mv mysqld_exporter-0.15.1.linux-amd64/mysqld_exporter /usr/local/bin/ && \
    rm -rf mysqld_exporter-0.15.1.linux-amd64*

# Copy entrypoint script
COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

# Listen port for Prometheus scraping
EXPOSE 9104

# Entrypoint handles the secret extraction and execution
ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
