# 🧭 User Operations Guide - Inception

Welcome to the operations manual for the Inception infrastructure. This document provides a quick-reference guide for accessing and utilizing the deployed services without needing to dive into the source code.

## 🗺️ Endpoints Map (Where to Access What)

Once the infrastructure is deployed (`make bonus`), you can interact with the various services via the following entry points.

| Service | Access URL / Endpoint | Protocol | Description |
| :--- | :--- | :--- | :--- |
| **WordPress** | `https://serjimen.42.fr` | HTTPS | The main application layer. Access the public-facing blog or the admin panel (`/wp-admin`). |
| **Adminer** | `https://serjimen.42.fr/adminer/` | HTTPS | Web-based database management tool. Allows you to view and edit MariaDB tables directly. |
| **Static Site** | `https://serjimen.42.fr/cheatsheet/` | HTTPS | A lightweight, responsive static HTML page providing a quick cheatsheet for developers. |
| **Grafana** | `http://localhost:3000` | HTTP | The central observability dashboard. Visualizes real-time metrics scraped from MariaDB. |
| **FTP Server** | `ftp://localhost` | FTP | Secure file transfer endpoint. Allows uploading plugins or themes directly to the WordPress volume. |

> [!NOTE]
> If you are accessing the infrastructure from a host machine instead of a local VM, replace `localhost` with the VM's IP address (e.g., `http://<VM_IP>:3000`).

## 🔑 Credentials Cheat Sheet

To log into the various services, you will need the credentials defined in your `.env` and `secrets/` files. Below is a map of which credentials are required for which service.

### WordPress Administration
- **URL**: `https://serjimen.42.fr/wp-admin`
- **Username**: Defined in `.env` as `WP_ADMIN_USER` (e.g., `wpadmin_inception`)
- **Password**: Found inside `secrets/credentials.txt`
- **Use Case**: Installing themes, managing users, writing blog posts.

### Database Management (Adminer)
- **URL**: `https://serjimen.42.fr/adminer/`
- **System**: Select `MySQL` (or MariaDB)
- **Server**: Type `mariadb` (This is the internal Docker DNS name)
- **Username**: Defined in `.env` as `MYSQL_USER` (e.g., `wpuser`)
- **Password**: Found inside `secrets/db_password.txt`
- **Use Case**: Executing raw SQL queries, backing up tables, debugging WordPress data.

### FTP Server
- **Client**: Any FTP client (e.g., FileZilla) or command-line `ftp`
- **Host**: `localhost` (Port 21)
- **Username**: Defined in `.env` as `FTP_USER` (e.g., `ftpuser`)
- **Password**: Defined in `.env` as `FTP_PASS` (e.g., `ftppassword`)
- **Use Case**: Directly modifying WordPress files (`wp-config.php`, uploading custom plugins) securely inside the chroot environment.

### Grafana Dashboards
- **URL**: `http://localhost:3000`
- **Username**: `admin` (Default Grafana admin user)
- **Password**: `admin` (Default Grafana password, you will be prompted to change it on first login).
- **Use Case**: Monitoring the health of the database. Navigate to `Dashboards > MariaDB Health Overview` to see real-time Uptime and Thread connections. No configuration is required thanks to Auto-Provisioning.

## 🛠️ Common Operations

### Uploading a WordPress Theme via FTP
1. Open your terminal: `ftp localhost`
2. Authenticate using `FTP_USER` and `FTP_PASS`.
3. Navigate to the themes directory: `cd wp-content/themes`
4. Use the `put` command to upload your files. The changes will instantly reflect on the live website because the FTP container shares a Bind Mount with the WordPress container.

### Monitoring Database Health
If the website feels slow, you can use the Observability Stack to diagnose the issue:
1. Open Grafana at `http://localhost:3000`.
2. Open the **MariaDB Health Overview** dashboard.
3. Check the "Threads Connected" graph. A massive spike could indicate an unoptimized WordPress plugin or a sudden surge in traffic.
