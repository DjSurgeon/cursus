# 📖 User Documentation - Inception

*This project has been created as part of the 42 curriculum by serjimen.*

## 🚀 Project Status
The infrastructure is in its **Final Implementation (Fully Functional)**. It features **High-Performance Orchestration** for rapid deployment during the evaluation.

---

## 🛠️ Provided Services
The stack provides a secure, containerized web environment consisting of:
- **NGINX:** The secure entry point (HTTPS) with TLS 1.2/1.3.
- **WordPress:** The CMS powered by PHP-FPM 8.2.
- **MariaDB:** The database engine v10.11+.

---

## 🕹️ Managing the Project
All management is done through the `Makefile` in the `intra/` directory.

- **To Start:** Run `make up-alpine`. Starts the services using Alpine Linux 3.22 (High-speed build).
- **To Stop:** Run `make down`.
- **Live Logs:** Run `make logs` to monitor the initialization and server activity.
- **Full Reset:** Run `make re`.

---

## 🏗️ Performance Boosts
This project has been optimized for the evaluation:
- **Parallel Deployment:** Services launch simultaneously.
- **BuildKit Engine:** High-speed image processing with Buildx/Bake.
- **Smart Filtering:** Only essential files are used to reduce build context size.

---

## 🌐 Accessing the Website
Once the services are running:
1.  **Main Site:** [https://serjimen.42.fr](https://serjimen.42.fr).
2.  **Admin Panel:** [https://serjimen.42.fr/wp-admin](https://serjimen.42.fr/wp-admin).

*Note: Due to self-signed SSL certificates, you must bypass the browser security warning.*

---

## ✅ Checking System Health
To verify that everything is running correctly:
- **Service Status:** Run `make ps`. All containers (**mariadb, wordpress, nginx**) should show a status of `Up`.
- **Persistence:** Verify that `/home/${LOGIN}/data` contains the database and WordPress files.
- **Connectivity:** Ensure you can ping `serjimen.42.fr` from your host machine.
