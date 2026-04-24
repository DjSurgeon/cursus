# 🛠️ Developer Documentation - Inception

This document provides technical details for developers to set up, manage, and extend the Inception infrastructure.

---

## 🚀 Current Status
- **Core Orchestration:** The `Makefile` manages the complete stack (**Alpine 3.22**) with high-speed **Docker Buildx / Bake optimizations**.
- **MariaDB Service:** Fully implemented (v10.11+) with secure Docker Secrets.
- **WordPress Service:** Fully implemented with PHP-FPM 8.2 and WP-CLI installation.
- **NGINX Service:** Secure TLS entry point (v1.2/1.3) fully configured.
- **Networking:** Private `bridge` network `inception` for internal communication.
- **Persistence:** High-performance local bind mounts in `/home/${LOGIN}/data/...`.

---

## 🏗️ Performance & Build Optimization

To ensure the fastest possible build times, the following features have been implemented:

1.  **Docker Buildx & Bake:**
    - Integrated with **BuildKit** for parallel layer building and smarter caching.
    - Automated detection and setup via `phase01.sh`.
2.  **Parallel Building:**
    - Services build simultaneously by default in Docker Compose V2.
3.  **Build Context Filtering:**
    - A `.dockerignore` file in `srcs/` ensures only necessary source files are sent to the Docker daemon.

---

## 🏗️ Environment Setup (Zero to Hero)

If you are on a clean Ubuntu 24.04 environment, follow these steps for an automated setup:

### 1. System Preparation
Run the system setup script to install Docker, Buildx, and configure volumes:
```bash
bash scripts/phase01.sh <your_login>
```

### 2. Configuration & Secrets
Generate the required environment variables and secrets:
1.  **Generate `.env`:** `bash scripts/phase03.sh <your_login>`
2.  **Generate Secrets:** `bash scripts/phase.sh` (Creates passwords in `~/secrets`).

### 3. Domain Mapping
Ensure your host's `/etc/hosts` maps the local domain:
```text
127.0.0.1  serjimen.42.fr
```

---

## 🚀 Building and Launching

The infrastructure is managed via the optimized `intra/Makefile`.

```bash
make up-alpine  # Recommended: Launches Alpine 3.22-based images
```

---

## 🔧 Management Commands

| Command | Action |
| :--- | :--- |
| `make up-alpine` | Start containers using Alpine-based images (Default). |
| `make ps` | Check container health and port mapping. |
| `make logs` | Stream real-time logs for all services. |
| `make clean` | Stop and remove containers and volumes. |
| `make fclean` | **Total Wipe:** Full clean + physical deletion of data folders. |

---

## 🔍 Technical Implementation Details

- **PID 1 Logic:** Every setup script ends with `exec <service>`, ensuring the service receives signals directly.
- **Security:** Validation checks ensure secrets are present in `/run/secrets/` before service initialization.
- **Stack Versions:** Alpine 3.22, MariaDB 10.11+, PHP 8.2, NGINX.
