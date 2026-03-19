*This project has been created as part of the 42 curriculum by serjimen.*

# 🐳 Inception - System Administration with Docker

## 📝 Description
**Inception** is a foundational infrastructure project at 42 that challenges students to build a complete web stack from scratch using **Docker Compose**. The goal is to orchestrate a secure, multi-container environment (NGINX, WordPress, MariaDB) where every service is built from a base OS image (Alpine or Debian).

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
    make up-alpine  # To launch with Alpine Linux (Recommended)
    # OR
    make up-debian  # To launch with Debian Bookworm
    ```

---

## 🏗️ Project Description

### High-Performance Orchestration
This project is optimized for rapid deployment and development:
- **BuildKit Engine:** Enabled by default for faster, parallelized layer building.
- **Parallel Deployment:** Services are built and started simultaneously to minimize wait times.
- **Context Filtering:** Uses `.dockerignore` to ensure only necessary source files are sent to the Docker daemon.

### Architecture & Design Choices
- **Single Entry Point:** NGINX acts as a reverse proxy, handling all TLS termination on port 443.
- **Multi-OS Support:** Every service is prepared for both **Alpine 3.22** and **Debian Bookworm**.
- **Process Integrity:** Initialization scripts use `exec` to ensure the main service runs as PID 1.

---

## 📚 Resources

### AI Usage
AI (Gemini CLI) was used in this project for the following tasks:
- **Orchestration:** Implementing a dual-OS `Makefile` strategy for Alpine/Debian environments.
- **Optimization:** Refactoring `Dockerfiles` and setup scripts for cross-distro compatibility and implementing high-speed build flags (BuildKit, Parallelism).
- **Documentation:** Assisting in the synthesis of technical concepts for `README.md`, `DEV_DOC.md`, and `USER_DOC.md`.
