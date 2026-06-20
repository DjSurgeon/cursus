# 🛠️ Developer Documentation - Inception

This document provides technical details for developers and evaluators required to audit, manage, and understand the internal architecture of the Inception infrastructure.

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

### 3. Secrets Management (Strict Compliance)
To maintain security compliance, sensitive credentials must not be declared within the `.env` file. Instead, create a `secrets/` directory at the root of the project (ensure this directory is listed in `.gitignore`). Within this directory, create the following text files containing the respective passwords:
- `db_password.txt`
- `db_root_password.txt`
- `credentials.txt` (Used for WP user credentials mapping if necessary)
- `mariadb_exporter_pwd.txt` (Required for the Observability Stack bonus)

## Build and Launch the Project

The infrastructure orchestration is automated via the `Makefile` located at the root of the repository, interfacing with Docker Compose.

To compile the mandatory infrastructure (3 core containers):
```bash
make up
```

To compile the **Full Infrastructure (10 Containers)** using Docker Compose profiles:
```bash
make bonus
```

During this process:
1. Docker Compose parses `srcs/docker-compose.yml`.
2. The custom `inception` bridge network is created.
3. The specified Dockerfiles for all 10 services are built from scratch utilizing the minimal `alpine:3.22` base image.
4. Services are initialized in foreground mode, strictly enforcing the PID 1 requirement using `exec`.
5. Grafana uses **Auto-Provisioning** to load the MariaDB dashboard automatically via `/usr/share/grafana/conf/provisioning/` without any manual UI clicks.

## Data Storage and Persistence

Data persistence is strictly handled via **Docker Bind Mounts**, directly linking host directories to container paths as required by the subject.

**Host Storage Location:**
Project data is persistently stored on the host filesystem under:
- MariaDB Data: `/home/serjimen/data/mariadb`
- WordPress Data: `/home/serjimen/data/wordpress`

If a container is stopped or rebuilt, the data remains intact on the host machine. The `Makefile` automatically sets up the correct ownership and permissions for these directories before launching Docker.

## Reverse Proxy Architecture

To maintain strict security and adhere to the "Only NGINX on port 443" rule while deploying bonus web interfaces (Adminer, Static Website), NGINX is configured as a Reverse Proxy.

- **Adminer:** Exposed internally on port `8080`. NGINX intercepts `https://serjimen.42.fr/adminer/` and proxies the traffic.
- **Static Website:** Exposed internally on port `1337`. NGINX intercepts `https://serjimen.42.fr/cheatsheet/` and proxies the traffic.

*Note on Grafana:* Grafana is exposed directly on port `3000` via HTTP. This is standard practice for the Observability bonus to avoid subpath routing conflicts, while keeping the main application securely behind NGINX.

## Container Fault Tolerance (Restart Loops)

During the `make bonus` launch, the `mariadb-exporter` container might crash and restart exactly once during the first few seconds. **This is expected behavior**. 
Docker Compose's `depends_on` only waits for the MariaDB container to start, not for its internal database initialization (`db-setup.sh`) to finish. The exporter attempts to connect instantly, fails because the `exporter` user hasn't been created yet, and exits. Docker Compose automatically restarts it, by which time MariaDB is ready, and the connection succeeds cleanly.

## Evaluation & Audit Guidelines

This section provides a standardized set of commands to verify the strict compliance of the infrastructure against the project requirements. 

### Block 1: Infrastructure Audit & Control

- **List active containers, their statuses, and exposed ports (Must be exactly 10 containers for full bonus):**
  ```bash
  docker ps
  ```
  *Note: Only ports 443 (NGINX), 21 + Passive Range (FTP), and 3000 (Grafana) should be exposed to `0.0.0.0`.*

- **Inspect the custom network to confirm container attachments:**
  ```bash
  docker network inspect srcs_inception
  ```

### Block 2: Network & Security Testing (cURL)
These commands verify that NGINX is the sole entry point for the core app, that SSL/TLS is strictly enforced, and that internal routing functions correctly.

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
The evaluator may request to inspect the internal filesystem of the containers or verify that processes are running as PID 1.

- **Access the interactive shell of a container (e.g., FTP):**
  ```bash
  docker exec -it ftp sh
  ```
- **Verify PID 1 compliance (example with MariaDB):**
  ```bash
  docker exec -it mariadb ps aux
  ```
  *(The primary process, `mysqld`, must be running as PID 1).*
