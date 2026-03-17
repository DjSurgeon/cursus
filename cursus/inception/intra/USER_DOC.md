# 📖 User Documentation - Inception

*This project has been created as part of the 42 curriculum by serjimen.*

## 🚀 Project Status
The infrastructure is currently in **active development**. 
- **Phase 1 (MariaDB):** Completed and secured with Docker Secrets.
- **Phase 2 (WordPress & NGINX):** Orchestration is configured and ready for implementation.

---

## 🛠️ Provided Services
The stack provides a secure, containerized web environment consisting of:
- **NGINX:** The secure entry point (HTTPS) that routes traffic.
- **WordPress:** The website engine and content management system (CMS).
- **MariaDB:** The database engine that stores all site data.

---

## 🕹️ Managing the Project
All management is done through the `Makefile` located in the `intra/` directory.

- **To Start:** Run `make up`. This will create the necessary data folders, build the images, and start the services in the background.
- **To Stop:** Run `make down`. This stops the containers but keeps your data safe.
- **To Restart:** Run `make restart`.
- **Full Reset:** Run `make re` (Warning: This rebuilds everything).

---

## 🌐 Accessing the Website
Once the services are running:
1.  **Main Site:** Open your browser and go to [https://serjimen.42.fr](https://serjimen.42.fr).
2.  **Admin Panel:** Access the WordPress dashboard at [https://serjimen.42.fr/wp-admin](https://serjimen.42.fr/wp-admin).

*Note: Since we use self-signed certificates, your browser will show a security warning. It is safe to click "Advanced" and "Proceed" for this local development environment.*

---

## 🔐 Credentials & Security
For security reasons, passwords are **never** stored in the code or environment variables.
- **Location:** All sensitive credentials are stored in the `secrets/` directory at the project root.
- **Files:**
    - `db_password.txt`: Password for the regular database user.
    - `db_root_password.txt`: Password for the database administrator.
    - `credentials.txt`: Contains the WordPress admin and user passwords.

---

## ✅ Checking System Health
To verify that everything is running correctly:
- **Service Status:** Run `make ps`. All containers should show a status of `Up` or `Running`.
- **Live Logs:** Run `make logs` to see the real-time activity of all services. This is the best way to diagnose connection or setup issues.
- **Connectivity:** Ensure you can ping `serjimen.42.fr` (ensure it is mapped in your `/etc/hosts`).
