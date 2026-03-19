# 🛠️ Developer Documentation - Inception

This document provides technical details for developers to set up, manage, and extend the Inception infrastructure.

---

## 🚀 Current Status
- **Core Orchestration:** The `Makefile` supports dual environments (**Alpine 3.22** and **Debian Bookworm**) with **High-Performance BuildKit optimizations**.
- **MariaDB Service:** Fully implemented and consistent across both distributions.
- **WordPress Service:** Configuration and setup scripts are prepared for both distributions.
- **Networking:** Private `bridge` network `inception` is configured.
- **Persistence:** Local bind mounts are configured for `${LOGIN}/data/...`.

---

## 🏗️ Performance & Build Optimization

To ensure the fastest possible build times during development and evaluation, the following features have been implemented:

1.  **Docker BuildKit:**
    - Enabled via `export DOCKER_BUILDKIT=1` in the `Makefile`.
    - Benefits: Faster builds, improved layer caching, and parallel stage execution.
2.  **Parallel Building:**
    - Using `--parallel` in the `up` target allows MariaDB and WordPress to build simultaneously.
3.  **Build Context Filtering:**
    - A `.dockerignore` file in `srcs/` prevents documentation, secrets, and local logs from being uploaded to the Docker daemon.

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
  ```

### 3. Secrets Management
The project uses **Docker Secrets** to avoid exposing sensitive data.
- Create a `secrets/` directory at the project root.
- Required files: `db_password.txt`, `db_root_password.txt`, `credentials.txt`.

---

## 🚀 Building and Launching

The infrastructure is managed via the `intra/Makefile`.

```bash
make up-alpine  # Launches using Dockerfile.alpine (High speed)
make up-debian  # Launches using Dockerfile.debian
```

---

## 🔧 Management Commands

| Command | Action |
| :--- | :--- |
| `make up-alpine` | Start containers using Alpine-based images (Default). |
| `make up-debian` | Start containers using Debian-based images. |
| `make ps` | Check container health and port mapping. |
| `make logs` | Stream real-time logs for all services. |
| `make fclean` | **Total Wipe:** Includes physical deletion of host data folders. |

---

## 🔍 Technical Implementation Details

- **PID 1 Logic:** Every setup script ends with `exec <service>`, ensuring the service receives signals directly.
- **Distro Consistency:** We maintain parallel `Dockerfile.alpine`/`Dockerfile.debian` to offer OS flexibility.
- **Security:** Validation checks ensure secrets are present in `/run/secrets/` before initialization.
