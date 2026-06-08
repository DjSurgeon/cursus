# 🛠️ Developer Documentation - Inception

This document provides technical details for developers required to set up, manage, and extend the Inception infrastructure.

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
CERTS_CRT=/etc/ssl/certs/inception.crt
CERTS_KEY=/etc/ssl/private/inception.key
MYSQL_DATABASE=wordpress
MYSQL_USER=wpuser
WP_URL=serjimen.42.fr
WP_TITLE=Inception
WP_ADMIN_USER=wpadmin_inception
WP_USER=wpuser
```

### 3. Secrets Management
To maintain security compliance, sensitive credentials must not be declared within the `.env` file. Instead, create a `secrets/` directory at the root of the project (ensure this directory is listed in `.gitignore`). Within this directory, create the following text files containing the respective passwords:
- `db_password.txt`
- `db_root_password.txt`
- `wp_admin_password.txt`
- `wp_password.txt`

## Build and Launch the Project

The infrastructure orchestration is automated via the `Makefile` located at the root of the repository, interfacing with Docker Compose.

To compile the container images and launch the infrastructure in detached mode, execute:
```bash
make up
```
This target invokes `docker-compose up -d --build`. During this process:
1. Docker Compose parses `srcs/docker-compose.yml`.
2. The custom `inception` bridge network is created.
3. The specified Dockerfiles for NGINX, WordPress, and MariaDB are built from scratch utilizing the minimal Alpine base image.
4. Secrets are securely mounted into the containers at runtime.
5. Services are initialized, strictly enforcing the PID 1 requirement.

## Container and Volume Management

The `Makefile` exposes specific targets for infrastructure lifecycle management:

- **Start/Rebuild:** `make up` (Builds and starts containers in the background).
- **Stop:** `make down` (Gracefully terminates containers and removes the network).
- **Restart:** `make restart` (Restarts the active containers without rebuilding).
- **Monitoring:** `make ps` (Displays the status of the infrastructure containers).
- **Logging:** `make logs` (Attaches to the active STDOUT/STDERR streams of the containers).
- **Cleanup:** `make clean` (Removes containers, orphans, dangling images, and Docker volumes).
- **Deep Cleanup:** `make fclean` (Executes `clean` and subsequently removes the host data directories).

For granular debugging, utilize raw Docker commands. For example, to instantiate an interactive shell inside the database container:
```bash
docker exec -it mariadb sh
```

## Data Storage and Persistence

Data persistence is strictly handled via Docker Bind Mounts, directly linking host directories to container paths.

**Host Storage Location:**
Project data is persistently stored on the host filesystem under:
- MariaDB Data: `/home/serjimen/data/mariadb`
- WordPress Data: `/home/serjimen/data/wordpress`

**Persistence Mechanism:**
The `docker-compose.yml` defines bind mounts connecting `/var/lib/mysql` (within the MariaDB container) and `/var/www/html` (within the WordPress container) to their respective host directories. If a container is stopped, restarted, or entirely rebuilt, the data remains intact on the host machine. Upon re-instantiation, the containers remount these directories, seamlessly restoring previous database schemas, user uploads, and configuration states.

## Evaluation & Audit Guidelines

This section provides a standardized set of commands to verify the strict compliance of the infrastructure against the project requirements. These commands are typically utilized during the peer evaluation process.

### Block 1: Infrastructure Audit & Control
The evaluator will utilize these commands to inspect the active state of the orchestration.

- **List active containers, their statuses, and exposed ports:**
  ```bash
  docker ps
  ```
- **Stream real-time logs for all services, or specifically for NGINX:**
  ```bash
  docker compose -f srcs/docker-compose.yml logs -f
  docker compose -f srcs/docker-compose.yml logs -f nginx
  ```
- **Verify the existence of the dedicated custom network (Host networking is strictly prohibited):**
  ```bash
  docker network ls
  ```
- **Inspect the custom network to confirm container attachments:**
  ```bash
  docker network inspect srcs_inception
  ```
- **List all created Named Volumes:**
  ```bash
  docker volume ls
  ```
- **Inspect a volume to verify its Mountpoint correctly points to the host machine (`/home/${USER}/data/...`):**
  ```bash
  docker volume inspect srcs_wp_data
  ```

### Block 2: Network & Security Testing (cURL)
These commands verify that NGINX is the sole entry point and that SSL/TLS is strictly enforced.

*Note: If testing on a development environment using a non-standard port (e.g., `8443`), append `:8443` to the host in the commands below. In the campus evaluation environment, use the standard ports (80/443).*

- **Test HTTP connection (Must fail or redirect to HTTPS):**
  ```bash
  curl -I http://serjimen.42.fr
  ```
- **Test HTTPS connection bypassing self-signed certificate warnings (Must return HTTP/1.1 200 OK or 301 Redirect):**
  ```bash
  curl -k -I https://serjimen.42.fr
  ```
- **Verify strict TLS restrictions. TLSv1.1 MUST fail, and TLSv1.2 MUST succeed:**
  ```bash
  curl -k -I --tls-max 1.1 https://serjimen.42.fr  # MUST FAIL
  curl -k -I --tlsv1.2 https://serjimen.42.fr      # MUST SUCCEED
  ```

### Block 3: Interactive Container Inspection
The evaluator may request to inspect the internal filesystem of the containers to ensure no prohibited software is installed (e.g., verifying NGINX is not installed inside the WordPress container) or to locate configuration files.

- **Access the interactive shell of the WordPress container:**
  ```bash
  docker exec -it wordpress sh
  ```
- **Access the interactive shell of the NGINX container:**
  ```bash
  docker exec -it nginx sh
  ```
- **Access the interactive shell of the MariaDB container:**
  ```bash
  docker exec -it mariadb sh
  ```
