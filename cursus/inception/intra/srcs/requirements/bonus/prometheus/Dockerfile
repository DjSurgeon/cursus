# Base image
FROM alpine:3.22

# Install Prometheus package
RUN apk add --no-cache prometheus

# Create data directory with correct ownership
RUN mkdir -p /prometheus && chown -R nobody:nobody /prometheus /etc/prometheus

# Copy configuration file
COPY conf/prometheus.yml /etc/prometheus/prometheus.yml

# Switch to nobody user for security (Prometheus doesn't need root)
USER nobody

# Listen port
EXPOSE 9090

# Run prometheus in foreground as PID 1
ENTRYPOINT ["/usr/bin/prometheus", "--config.file=/etc/prometheus/prometheus.yml", "--storage.tsdb.path=/prometheus"]
