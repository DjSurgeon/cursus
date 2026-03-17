*This project has been created as part of the 42 curriculum by serjimen.*

# 🐳 Inception - System Administration with Docker

## 📝 Description
**Inception** is a foundational infrastructure project at 42 that challenges students to build a complete web stack from scratch using **Docker Compose**. The goal is to orchestrate a secure, multi-container environment (NGINX, WordPress, MariaDB) where every service is built from a base OS image (Alpine or Debian) rather than using pre-built images from Docker Hub.

The project emphasizes **Infrastructure as Code (IaC)**, security best practices (TLS, Secrets), and process management (PID 1).

---

## 🚀 Instructions

### 1. Prerequisites
- A Linux environment (Ubuntu/Debian) or a Virtual Machine.
- Docker and Docker Compose installed.
- Map the project domain in your `/etc/hosts`:
  ```bash
  127.0.0.1  serjimen.42.fr
  ```

### 2. Installation & Execution
1.  **Clone the repository:**
    ```bash
    git clone <repository-url> inception
    cd inception/intra
    ```
2.  **Configure Secrets:**
    Create a `secrets/` directory at the project root and add `db_password.txt`, `db_root_password.txt`, and `credentials.txt`.
3.  **Launch:**
    ```bash
    make up
    ```
4.  **Access:**
    Visit [https://serjimen.42.fr](https://serjimen.42.fr).

---

## 🏗️ Project Description

### Architecture & Design Choices
- **Single Entry Point:** NGINX acts as a reverse proxy, handling all TLS termination on port 443. No other services are exposed to the host.
- **Custom Builds:** Every service uses a custom `Dockerfile` based on `alpine:3.22` (penultimate stable version) or `debian:bookworm` to ensure full control over the environment.
- **Process Integrity:** Initialization scripts use `exec` to ensure the main service (e.g., `mysqld`) runs as PID 1, allowing for proper signal handling and container lifecycle management.

### Key Comparisons

| Feature | Virtual Machines (VM) | Docker Containers |
| :--- | :--- | :--- |
| **Isolation** | Hardware-level (Hypervisor) | OS-level (Namespaces/Cgroups) |
| **Resources** | High (Full OS per VM) | Low (Shares Host Kernel) |
| **Speed** | Minutes to boot | Seconds to start |

| Feature | Environment Variables (.env) | Docker Secrets |
| :--- | :--- | :--- |
| **Visibility** | Visible in `docker inspect` | Only visible inside the container as a file |
| **Persistence** | Stored in memory/logs | Stored securely in `/run/secrets/` |
| **Use Case** | Non-sensitive configuration | Passwords, Keys, Certificates |

| Feature | Host Network | Docker Bridge Network |
| :--- | :--- | :--- |
| **Isolation** | None (shares host IP/ports) | High (Private virtual network) |
| **Resolution** | Requires IP management | Internal DNS (Service names as hostnames) |
| **Security** | Services exposed by default | Services hidden from the outside world |

| Feature | Bind Mounts | Docker Volumes |
| :--- | :--- | :--- |
| **Management** | User-managed (specific host path) | Docker-managed (internal storage) |
| **In Inception** | Required for `/home/login/data/` | Used for abstract persistent storage |
| **Portability** | Depends on host file structure | Fully portable across Docker hosts |

---

## 📚 Resources

### References
- [Docker Documentation](https://docs.docker.com/)
- [MariaDB Official Knowledge Base](https://mariadb.com/kb/en/)
- [NGINX Reverse Proxy Guide](https://docs.nginx.com/nginx/admin-guide/web-server/reverse-proxy/)
- [42 Subject v5.0 Instructions]

### AI Usage
AI (Gemini CLI) was used in this project for the following tasks:
- **Boilerplate Generation:** Creating the initial structure for `Makefiles` and `Dockerfiles`.
- **Optimization:** Refactoring the `Makefile` for shell compatibility (bash/zsh) and adding colored help menus.
- **Pedagogic Scripting:** Enhancing the initialization scripts with color-coded feedback and robust secret validation for a better defense experience.
- **Documentation:** Assisting in the synthesis of technical concepts for `README.md`, `DEV_DOC.md`, and `USER_DOC.md` to ensure compliance with the subject rules.
- **Security Auditing:** Verifying that no passwords or sensitive data were leaked into the source code or environment variables during development.
