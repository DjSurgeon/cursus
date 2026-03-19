# 📖 User Documentation - Inception

*This project has been created as part of the 42 curriculum by serjimen.*

## 🚀 Project Status
The infrastructure is in **Phase 2 (WordPress & NGINX)**. It features **High-Performance Orchestration** for rapid deployment during the evaluation.

---

## 🛠️ Provided Services
The stack provides a secure, containerized web environment consisting of:
- **NGINX:** The secure entry point (HTTPS).
- **WordPress:** The CMS powered by PHP-FPM.
- **MariaDB:** The database engine.

---

## 🕹️ Managing the Project
All management is done through the `Makefile` in the `intra/` directory.

- **To Start (Recommended):** Run `make up-alpine`. Starts the services using Alpine Linux (High-speed build).
- **To Start (Debian):** Run `make up-debian`. Starts the services using Debian Bookworm.
- **To Stop:** Run `make down`.
- **Live Logs:** Run `make logs` to monitor the initialization process.
- **Full Reset:** Run `make re`.

---

## 🏗️ Performance Boosts
This project has been optimized to start as quickly as possible:
- **Parallel Builds:** Services launch simultaneously.
- **BuildKit Engine:** Faster image processing.
- **Smart Filtering:** Only essential files are used during the build.

---

## 🌐 Accessing the Website
Once the services are running:
1.  **Main Site:** [https://serjimen.42.fr](https://serjimen.42.fr).
2.  **Admin Panel:** [https://serjimen.42.fr/wp-admin](https://serjimen.42.fr/wp-admin).

*Note: Due to self-signed SSL certificates, you must bypass the browser security warning.*

---

## ✅ Checking System Health
To verify that everything is running correctly:
- **Service Status:** Run `make ps`. All containers should show a status of `Up`.
- **Connectivity:** Ensure you can ping `serjimen.42.fr` (mapped in your `/etc/hosts`).
