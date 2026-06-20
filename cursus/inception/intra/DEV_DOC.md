# 🛠️ Developer Documentation - Inception

This document provides technical details for developers required to set up, manage, and extend the Inception infrastructure, including advanced reverse-proxy routing and bonus services.

## Environment Setup From Scratch

To establish the environment on a pristine host machine, manual configuration of prerequisite variables and system settings is required.

### 1. Prerequisites and Host Configuration
Before initiating the build process, you must ensure local DNS resolution maps the application domain to the loopback interface. 
Modify the `/etc/hosts` file on the host machine to include the following entry:
```text
127.0.0.1  serjimen.42.fr
```

### 2. Configuration Files (`.env`)
Create a `.env` file within the `srcs/` directory. This file must define all necessary non-sensitive environment variables required by the `docker-compose.yml` configuration:
```env
DOMAIN_NAME=serjimen.42.fr
MYSQL_DATABASE=wordpress
MYSQL_USER=wpuser
WP_ADMIN_USER=wpadmin_inception
WP_ADMIN_EMAIL=admin@42.fr
WP_USER=wpuser
WP_USER_EMAIL=user@42.fr
FTP_USER=ftpuser
FTP_PASS=ftppassword
```

### 3. Secrets Management
To maintain security compliance, sensitive credentials must not be declared within the `.env` file. Instead, create a `secrets/` directory at the root of the project (ensure this directory is listed in `.gitignore`). Within this directory, create the following text files containing the respective passwords:
- `db_password.txt`
- `db_root_password.txt`
- `credentials.txt` (Used for WP user credentials mapping if necessary)

## Build and Launch the Project

The infrastructure orchestration is automated via the `Makefile` located at the root of the repository, interfacing with Docker Compose.

To compile the mandatory infrastructure:
```bash
make up
```

To compile the **Full Infrastructure (Mandatory + Bonuses)** using Docker Compose profiles:
```bash
make bonus
```

During this process:
1. Docker Compose parses `srcs/docker-compose.yml`.
2. The custom `inception` bridge network is created.
3. The specified Dockerfiles for all services (NGINX, WordPress, MariaDB, FTP, Redis, Adminer, Static) are built from scratch utilizing the minimal `alpine:3.22` base image.
4. Services are initialized in background mode (`-d`), strictly enforcing the PID 1 requirement.

## Container and Volume Management

The `Makefile` exposes specific targets for infrastructure lifecycle management:

- **Start Core:** `make up`
- **Start All (Profiles):** `make bonus`
- **Stop:** `make down` (Gracefully terminates containers and removes the network).
- **Restart:** `make restart`
- **Monitoring:** `make ps`
- **Logging:** `make logs`
- **Cleanup:** `make clean` (Removes containers, orphans, dangling images, and Docker volumes).
- **Deep Cleanup:** `make fclean` (Executes `clean` and subsequently removes the host data directories).

## Data Storage and Persistence

Data persistence is strictly handled via Docker Bind Mounts, directly linking host directories to container paths.

**Host Storage Location:**
Project data is persistently stored on the host filesystem under:
- MariaDB Data: `/home/serjimen/data/mariadb`
- WordPress Data: `/home/serjimen/data/wordpress`

**Persistence Mechanism:**
The `docker-compose.yml` defines bind mounts connecting `/var/lib/mysql` (MariaDB) and `/var/www/html` (WordPress) to their respective host directories. The FTP container also mounts the WordPress volume to allow direct file modification. If a container is stopped or rebuilt, the data remains intact on the host machine.

## Reverse Proxy Architecture

To maintain strict security and adhere to the "Only NGINX on port 443" rule while deploying bonus web interfaces (Adminer, Static Website), NGINX is configured as a Reverse Proxy.
- **Adminer:** Exposed internally on port `8080`. NGINX intercepts `https://serjimen.42.fr/adminer/` and proxies the traffic.
- **Static Website:** Exposed internally on port `1337`. NGINX intercepts `https://serjimen.42.fr/cheatsheet/` and proxies the traffic.

## Evaluation & Audit Guidelines

This section provides a standardized set of commands to verify the strict compliance of the infrastructure against the project requirements. 

### Block 1: Infrastructure Audit & Control

- **List active containers, their statuses, and exposed ports (Must be 7 containers for full bonus):**
  ```bash
  docker ps
  ```
  *Note: Only ports 443 (NGINX) and 21 + Passive Range (FTP) should be exposed to `0.0.0.0`.*

- **Inspect the custom network to confirm container attachments:**
  ```bash
  docker network inspect srcs_inception
  ```

### Block 2: Network & Security Testing (cURL)
These commands verify that NGINX is the sole entry point, that SSL/TLS is strictly enforced, and that internal routing functions correctly.

- **Test HTTP connection (Must fail or redirect to HTTPS):**
  ```bash
  curl -I http://serjimen.42.fr
  ```
- **Test HTTPS connection to WordPress (Must return HTTP/1.1 200 OK or 301/302 Redirect):**
  ```bash
  curl -k -I https://serjimen.42.fr
  ```
- **Test Reverse Proxy to Adminer (Must return HTTP/1.1 200 OK):**
  ```bash
  curl -k -I https://serjimen.42.fr/adminer/
  ```
  *(Note: A request to `/adminer` without the trailing slash will return a 301 Redirect to append the slash. This is expected NGINX behavior).*

- **Test Reverse Proxy to Static Site (Must return HTTP/1.1 200 OK):**
  ```bash
  curl -k -I https://serjimen.42.fr/cheatsheet/
  ```

### Block 3: Interactive Container Inspection
The evaluator may request to inspect the internal filesystem of the containers.

- **Access the interactive shell of a container (e.g., FTP):**
  ```bash
  docker exec -it ftp sh
  ```
