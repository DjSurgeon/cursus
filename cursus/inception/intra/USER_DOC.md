# 📖 User Documentation - Inception

This document is intended for end users and administrators who need to understand, start, stop, and manage the Inception web infrastructure.

## Services Provided
The infrastructure provisions a secure, fully-functional WordPress environment. The stack consists of three core components:
- **NGINX:** Acts as the secure gateway (Reverse Proxy). It ensures that all incoming connections are encrypted via HTTPS (TLSv1.2/TLSv1.3).
- **WordPress:** The Content Management System (CMS) that provides the user-facing website and administration interface, processing dynamic requests via PHP-FPM.
- **MariaDB:** The backend database storing all website data, including posts, users, and configuration settings.

## Start and Stop the Project
The entire infrastructure is managed via a `Makefile` located in the root of the project directory.

- **To Start:** Open a terminal in the project directory and execute:
  ```bash
  make up
  ```
  This command will build the necessary images and launch all containers in the background.

- **To Stop:** To safely halt the infrastructure, execute:
  ```bash
  make down
  ```
  This command gracefully stops and removes the active containers while preserving your persistent data.

## Accessing the Website and Administration Panel
Ensure the services are running before attempting access.

- **Main Website:** Open your web browser and navigate to `https://serjimen.42.fr`. 
- **Administration Panel:** Navigate to `https://serjimen.42.fr/wp-admin` to access the WordPress backend dashboard.

*Note: Since the server utilizes self-signed SSL certificates for local testing, your browser may display a security warning. You must acknowledge the risk and proceed to the site.*

## Locating and Managing Credentials
Administrative and system credentials are provisioned securely. As an administrator, you can locate and manage configuration details across two distinct locations:
1. **`.env` File:** Located in the `srcs/` directory. This file contains non-sensitive configuration parameters, such as domain names, database names, and standard usernames.
2. **`secrets/` Directory:** Located in the root project directory. This directory contains discrete text files for sensitive passwords (e.g., `db_password.txt`, `wp_admin_password.txt`). These files are injected securely into the containers at runtime and are strictly ignored by version control systems to prevent unauthorized access.

If you need to update a password, modify the respective file within the `secrets/` directory prior to launching the stack.

## Checking System Health
To verify that all services are executing correctly:
1. Open a terminal in the project directory.
2. Execute the following command:
   ```bash
   make ps
   ```
3. The output will list all managed containers (`nginx`, `wordpress`, `mariadb`). Verify that the **STATUS** column for all services indicates `Up`.
