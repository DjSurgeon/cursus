# 📖 User Documentation - Inception

This document is intended for end users and administrators who need to understand, start, stop, and manage the Inception web infrastructure.

## Services Provided
The infrastructure provisions a secure, fully-functional WordPress environment along with several advanced administrative utilities. The stack consists of:

**Core Services:**
- **NGINX:** Acts as the secure gateway (Reverse Proxy). It ensures that all incoming connections are encrypted via HTTPS (TLSv1.2/TLSv1.3).
- **WordPress:** The Content Management System (CMS) that provides the user-facing website and administration interface, processing dynamic requests via PHP-FPM.
- **MariaDB:** The backend database storing all website data, including posts, users, and configuration settings.

**Bonus Services:**
- **Redis:** An internal caching layer that significantly speeds up WordPress load times.
- **FTP Server:** A vsftpd server allowing direct file uploads to the WordPress directory.
- **Static Website:** A portfolio/cheatsheet built in pure HTML/CSS.
- **Adminer:** A web-based database management interface.

## Start and Stop the Project
The entire infrastructure is managed via a `Makefile` located in the root of the project directory.

- **To Start Core Infrastructure:** Open a terminal in the project directory and execute:
  ```bash
  make up
  ```
- **To Start Full Infrastructure (with Bonuses):** 
  ```bash
  make bonus
  ```
  This command will build the necessary images and launch all 7 containers in the background.

- **To Stop:** To safely halt the infrastructure, execute:
  ```bash
  make down
  ```
  This command gracefully stops and removes the active containers while preserving your persistent data.

## Accessing the Websites and Interfaces
Ensure the services are running (`make bonus`) before attempting access.

- **Main Website:** Open your web browser and navigate to `https://serjimen.42.fr`. 
- **WordPress Admin Panel:** Navigate to `https://serjimen.42.fr/wp-admin/` to access the CMS dashboard.
- **Adminer (Database Manager):** Navigate to `https://serjimen.42.fr/adminer/` to securely manage MariaDB. Log in using `MySQL`, server: `mariadb`, and your credentials from `.env`.
- **Static Website (Cheatsheet):** Navigate to `https://serjimen.42.fr/cheatsheet/`.
- **FTP Access:** Use an FTP client (like FileZilla or `ftp` CLI) to connect to `serjimen.42.fr` on port `21`.

> **⚠️ Important Routing Note (Trailing Slashes):**
> When accessing directories or reverse-proxied services like `/wp-admin`, `/adminer`, or `/cheatsheet`, NGINX requires a trailing slash `/` at the end of the URL. If you omit it, NGINX will automatically issue a `301 Moved Permanently` redirect to append it. This is normal and expected behavior for secure web routing.

*Note: Since the server utilizes self-signed SSL certificates for local testing, your browser may display a security warning. You must acknowledge the risk and proceed to the site.*

## Locating and Managing Credentials
Administrative and system credentials are provisioned securely. As an administrator, you can locate and manage configuration details across two distinct locations:
1. **`.env` File:** Located in the `srcs/` directory. This file contains non-sensitive configuration parameters, such as domain names, database names, standard usernames, and FTP credentials (`FTP_USER`, `FTP_PASS`).
2. **`secrets/` Directory:** Located in the root project directory. This directory contains discrete text files for sensitive passwords (e.g., `db_password.txt`, `wp_admin_password.txt`). These files are injected securely into the containers at runtime and are strictly ignored by version control systems to prevent unauthorized access.

If you need to update a password, modify the respective file within the `secrets/` directory prior to launching the stack.

## Checking System Health
To verify that all services are executing correctly:
1. Open a terminal in the project directory.
2. Execute the following command:
   ```bash
   make ps
   ```
3. The output will list all managed containers. Verify that the **STATUS** column for all services indicates `Up`.
