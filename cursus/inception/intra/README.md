*This project has been created as part of the 42 curriculum by serjimen.*

# 🐳 Inception - System Administration with Docker

## 📝 Description
**Inception** is a foundational infrastructure project at 42 that challenges students to build a complete web stack from scratch using **Docker Compose**. The goal is to orchestrate a secure, multi-container environment where every service is built from a base OS image (**Alpine 3.22**).

This implementation provides a fully orchestrated stack:
- **NGINX:** Secure entry point with TLSv1.2/v1.3.
- **WordPress + PHP-FPM:** Modern CMS with high-performance PHP processing.
- **MariaDB:** Robust relational database engine.

The project emphasizes **Infrastructure as Code (IaC)**, security best practices (TLS, Secrets), and process management (PID 1).

---

## 🚀 Instructions

### 1. Prerequisites
- A Linux environment (Ubuntu 24.04 recommended) or a Virtual Machine.
- Map the project domain in your `/etc/hosts`:
  ```bash
  127.0.0.1  serjimen.42.fr
  ```

### 2. Fast Setup (Recommended)
If you are on a clean Ubuntu 24.04 machine, use the provided automation scripts for a "Zero to Hero" setup:
1.  **System Setup:** `bash scripts/phase01.sh <your_login>` (Installs Docker, Buildx, creates volumes).
2.  **Secrets:** `bash scripts/phase.sh` (Generates passwords in `~/secrets`).
3.  **Environment:** `bash scripts/phase03.sh <your_login>` (Generates `srcs/.env`).

### 3. Execution
1.  **Launch:**
    ```bash
    cd intra
    make up-alpine  # Starts the entire stack (Recommended)
    ```

---

## 🏗️ Project Description

### High-Performance Orchestration
This project is optimized for rapid deployment:
- **Docker Buildx & Bake:** Enabled for faster, parallelized layer building.
- **Parallel Deployment:** Services are built and started simultaneously.
- **Context Filtering:** Uses `.dockerignore` to ensure only essential source files are sent to the Docker daemon.

### Architecture & Design Choices
- **Single Entry Point:** NGINX acts as a reverse proxy, handling all TLS termination on port 443.
- **Distribution:** Every service uses **Alpine 3.22** for a minimal footprint and security.
- **Process Integrity:** Initialization scripts use `exec` to ensure the main service runs as PID 1.

---

## 📚 Resources

### AI Usage
AI (Gemini CLI) was used in this project for the following tasks:
- **Orchestration:** Implementing a dual-OS `Makefile` strategy for Alpine/Debian environments.
- **Optimization:** Refactoring `Dockerfiles` and setup scripts for cross-distro compatibility and implementing high-speed build flags (BuildKit, Parallelism).
- **Documentation:** Assisting in the synthesis of technical concepts for `README.md`, `DEV_DOC.md`, and `USER_DOC.md`.
