#!/bin/sh

# Default credentials if not provided
FTP_USER=${FTP_USER:-ftpuser}

# Read FTP password from secrets for maximum security
if [ -f /run/secrets/credentials ]; then
    FTP_PASS=$(grep FTP_PASS /run/secrets/credentials | cut -d '=' -f2)
else
    echo "Error: Credentials secret not found!"
    exit 1
fi

# Check if user already exists
if ! id "$FTP_USER" >/dev/null 2>&1; then
    # Create the user
    adduser -D "$FTP_USER"
    
    # Set password
    echo "$FTP_USER:$FTP_PASS" | chpasswd

    # Add user to www-data group to share permissions with nginx/php if needed
    # Usually in alpine www-data is 82, or we just chown
    chown -R "$FTP_USER":"$FTP_USER" /var/www/html
    
    echo "FTP user '$FTP_USER' created and permissions granted."
fi

# Make sure the chroot dir exists
mkdir -p /var/empty

# Run vsftpd in foreground
exec vsftpd /etc/vsftpd/vsftpd.conf
