# Base image
FROM alpine:3.22

# Install vsftpd
RUN apk update && apk upgrade && \
    apk add --no-cache vsftpd

# Copy configuration and setup script
COPY conf/vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY tools/ftp-setup.sh /usr/local/bin/ftp-setup.sh

# Set execute permissions
RUN chmod +x /usr/local/bin/ftp-setup.sh

# Expose FTP port and passive mode ports
EXPOSE 21 21100-21110

# Start FTP
ENTRYPOINT ["/usr/local/bin/ftp-setup.sh"]
