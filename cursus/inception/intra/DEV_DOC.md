# 🛠️ Developer Documentation - Inception

This document provides technical details for developers to set up, manage, and extend the Inception infrastructure.

---

## 🚀 Current Status
- **Core Orchestration:** `Makefile` and `srcs/docker-compose.yml` are fully functional and optimized for multi-shell compatibility.
- **MariaDB Service:** Implemented using `alpine:3.22` (penultimate stable version). Secured with Docker Secrets and enhanced with a color-coded pedagogic initialization script.
- **Networking:** Private `bridge` network `inception` is configured.
- **Persistence:** Local bind mounts are ready for MariaDB and WordPress data.

---

## 🏗️ Environment Setup

### 1. Prerequisites
- **OS:** Linux (Ubuntu/Debian recommended) or a VM as per 42 subject rules.
- **Tools:** `docker` (v20.10+), `docker-compose-plugin`, and `make`.
- **Domain Mapping:** Add the following to your `/etc/hosts`:
  ```text
  127.0.0.1  serjimen.42.fr
  ```

### 2. Configuration Files
- **`.env`:** Create `intra/srcs/.env` based on `.env.example`.
  ```bash
  DOMAIN_NAME=serjimen.42.fr
  MYSQL_DATABASE=wordpress
  MYSQL_USER=wpuser
  # Note: Passwords are NOT here.
  ```

### 3. Secrets Management
The project uses **Docker Secrets** to avoid exposing sensitive data in environment variables.
- Create a `secrets/` directory at the project root (ignored by Git).
- Required files:
  - `db_password.txt`: Database user password.
  - `db_root_password.txt`: MariaDB root password.
  - `credentials.txt`: WordPress admin and user credentials.

---

## 🚀 Building and Launching

The infrastructure is managed entirely via the `intra/Makefile`.

```bash
cd intra
make up        # Build images and start containers in detached mode
```

This command:
1. Creates local directories for persistence (`/home/serjimen/data/...`).
2. Builds custom images from local `Dockerfiles` (specifically `Dockerfile.alpine`).
3. Orchestrates the startup sequence (MariaDB -> WordPress -> NGINX).

---

## 🔧 Management Commands

| Command | Action |
| :--- | :--- |
| `make help` | Show the color-coded help menu with all available targets. |
| `make ps` | Check container health and port mapping. |
| `make logs` | Stream real-time logs with color support (essential for debugging). |
| `make restart` | Soft restart of all services. |
| `make clean` | Stop containers and remove images/volumes. |
| `make fclean` | **Total Wipe:** Includes physical deletion of host data folders. |

---

## 💾 Data Persistence & Storage

To comply with the subject's persistence requirements, we use **Local Bind Mounts**.

- **MariaDB Data:** Stored at `/home/serjimen/data/mariadb/`. Maps to `/var/lib/mysql` inside the container.
- **WordPress Data:** Stored at `/home/serjimen/data/wordpress/`. Maps to `/var/www/html` inside the container.

**Technical Note:** Data persists even if containers are removed (`make down`). Only `make fclean` (which uses `sudo rm -rf`) will permanently delete the volumes.

---

## 🔍 Technical Implementation Details (Hito 1: MariaDB)

- **PID 1 Logic:** The `db-setup.sh` script concludes with `exec mysqld`. This ensures `mysqld` inherits PID 1, allowing it to receive termination signals directly from Docker.
- **Security & Validation:** Scripts now include validation checks to ensure secrets exist in `/run/secrets/` before execution, preventing silent failures.
- **Observability:** Initialization scripts feature color-coded output (Blue for progress, Green for success, Red for errors) for better clarity during the evaluation and debugging.
- **Network Isolation:** MariaDB is configured with `bind-address = 0.0.0.0` in `my.cnf`, but it is only reachable by other containers on the internal `inception` bridge network. No ports are exposed to the host machine.
