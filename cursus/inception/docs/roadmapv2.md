# 🐳 Inception — Zero to Hero Roadmap

> Step-by-step guide aligned with the 42 subject rules (v5.0).
> Each phase includes what to do, how to do it, and why.

---

## ⚠️ Golden Rules Before You Start

Before touching any file, engrave these rules in your mind. Violating them means **direct failure**:

```
✗ FORBIDDEN to pull pre‑built images (php:alpine, nginx:alpine, mariadb:latest...)
✗ FORBIDDEN to use the :latest tag in any FROM
✗ FORBIDDEN to put passwords in Dockerfiles or docker-compose.yml
✗ FORBIDDEN to commit credentials to the Git repository
✗ FORBIDDEN to use network: host, --link, links:
✗ FORBIDDEN to use tail -f, sleep infinity, while true, bash as entrypoint
✗ FORBIDDEN to manually create the network with docker network create

✓ ONLY FROM debian:<version> or FROM alpine:<version> is allowed
✓ One Dockerfile per service, written by you from scratch
✓ Penultimate stable version of Alpine or Debian
✓ Passwords only in secrets/ (ignored by Git)
✓ Configuration variables in .env (ignored by Git)
```

---

## Phase 1: Setup and Environment

### What needs to be done?
Prepare the virtual machine with everything needed to work.

### Why a VM?
The subject explicitly requires it. You cannot do the project directly on your host machine — it must run inside a virtual machine. This simulates a real server environment and isolates the project from your system.

### Steps

**1. Create the VM**

Use VirtualBox or any hypervisor. Recommendations:
- System: Debian 12 (Bookworm) or Ubuntu 22.04
- RAM: minimum 2GB, recommended 4GB
- Disk: minimum 20GB
- Enable network in bridge mode or NAT with port forwarding

**2. Install Docker and Docker Compose**

```bash
# Update packages
sudo apt-get update

# Install dependencies
sudo apt-get install -y ca-certificates curl gnupg

# Add Docker's official GPG key
sudo install -m 0755 -d /etc/apt/keyrings
curl -fsSL https://download.docker.com/linux/debian/gpg | \
    sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg

# Add Docker repository
echo "deb [arch=$(dpkg --print-architecture) \
    signed-by=/etc/apt/keyrings/docker.gpg] \
    https://download.docker.com/linux/debian \
    $(. /etc/os-release && echo "$VERSION_CODENAME") stable" | \
    sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

# Install Docker
sudo apt-get update
sudo apt-get install -y docker-ce docker-ce-cli containerd.io docker-compose-plugin

# Add your user to the docker group (to avoid using sudo every time)
sudo usermod -aG docker $USER
newgrp docker

# Verify installation
docker --version
docker compose version
```

**3. Configure the local domain**

The subject requires that `login.42.fr` points to your local IP. Edit the hosts file:

```bash
sudo nano /etc/hosts

# Add this line (replace login with your 42 login)
127.0.0.1    login.42.fr
```

**4. Create the data directories for volumes**

```bash
# Replace login with your 42 login
mkdir -p /home/login/data/wordpress
mkdir -p /home/login/data/mariadb
```

### Exclusion Files

**`.gitignore`** — exclude files from the Git repository (security):
```gitignore
# Secrets — NEVER in the repository
secrets/
srcs/.env

# Volume data
/home/*/data/

# System files
.DS_Store
*.swp
```

**`.dockerignore`** (inside each service folder) — exclude files from the Docker build context (speed optimization, not security):
```dockerignore
# Exclude unnecessary files when building the image
*.md
.git
.gitignore
```

> ⚠️ **Important difference**: `.gitignore` protects your repository. `.dockerignore` makes the build faster by excluding files Docker doesn't need to copy. They are independent and complementary.

---

## Phase 2: Directory Structure

### What needs to be done?
Create the exact structure required by the subject before writing a single line of code.

### Why this structure?
The subject defines it explicitly. The Makefile must be at the root, secrets outside `srcs/` for better isolation, and each service in its own folder with its own Dockerfile.

### Complete Structure

```
.                                ← repository root
├── Makefile                     ← orchestrates everything with docker compose
├── .gitignore                   ← protects secrets and .env from the repository
├── README.md                    ← main documentation (mandatory)
├── USER_DOC.md                  ← user documentation (mandatory)
├── DEV_DOC.md                   ← developer documentation (mandatory)
│
├── secrets/                     ← passwords (ignored by Git)
│   ├── credentials.txt          ← WordPress admin user and password
│   ├── db_password.txt          ← MariaDB user password
│   └── db_root_password.txt     ← MariaDB root password
│
└── srcs/                        ← all project code
    ├── .env                     ← environment variables (ignored by Git)
    ├── docker-compose.yml       ← service orchestration
    │
    └── requirements/            ← one directory per service
        ├── nginx/
        │   ├── Dockerfile
        │   ├── .dockerignore
        │   ├── conf/
        │   │   └── nginx.conf
        │   └── tools/           ← initialization scripts if needed
        │
        ├── wordpress/
        │   ├── Dockerfile
        │   ├── .dockerignore
        │   ├── conf/
        │   │   └── www.conf     ← php-fpm configuration
        │   └── tools/
        │       └── wp-setup.sh  ← script that installs and configures WordPress
        │
        ├── mariadb/
        │   ├── Dockerfile
        │   ├── .dockerignore
        │   ├── conf/
        │   │   └── my.cnf       ← MariaDB configuration
        │   └── tools/
        │       └── db-setup.sh  ← script that creates the DB and users
        │
        └── bonus/               ← only if you do the bonus
            ├── redis/
            ├── ftp/
            ├── adminer/
            └── static-site/
```

### Create the Structure in One Go

```bash
mkdir -p secrets
mkdir -p srcs/requirements/nginx/{conf,tools}
mkdir -p srcs/requirements/wordpress/{conf,tools}
mkdir -p srcs/requirements/mariadb/{conf,tools}
touch Makefile
touch srcs/.env
touch srcs/docker-compose.yml
touch secrets/credentials.txt
touch secrets/db_password.txt
touch secrets/db_root_password.txt
```

---

## Phase 3: Base Images — Built From Scratch

### What needs to be done?
Define the base image you will use for each service.

### ⚠️ The Most Violated Subject Rule

> "It is then **forbidden** to pull ready-made Docker images, as well as using services such as DockerHub (Alpine/Debian being excluded from this rule)."

This means:

```dockerfile
# ✗ FORBIDDEN — pre-built images from DockerHub
FROM php:8.2-fpm-alpine
FROM nginx:alpine
FROM mariadb:10.11
FROM wordpress:latest

# ✓ CORRECT — only base Alpine or Debian, you install everything
FROM debian:bookworm
FROM alpine:3.19
```

### Which Version to Use?

The subject requires the **penultimate stable version**. As of 2025:

| Distro  | Latest Stable  | Penultimate (use this) |
|---------|----------------|------------------------|
| Debian  | Debian 13 (Trixie) | **Debian 12 (Bookworm)** |
| Alpine  | Alpine 3.21    | **Alpine 3.20**        |

> ⚠️ Always verify the current penultimate version before starting — these change over time.

The choice between Alpine and Debian is yours. Alpine produces smaller images but uses `apk` instead of `apt` and `musl` instead of `glibc`, which can cause incompatibilities. Debian is more familiar and compatible. For Inception, **Debian is more recommended** if you're learning.

---

## Phase 4: Mandatory Services

### 4.1 MariaDB

**What is it?** The database management system. It stores all WordPress data (posts, users, configuration).

**Why MariaDB and not MySQL?** They are practically compatible, but MariaDB is fully open source. The subject explicitly specifies it.

**MariaDB Dockerfile:**

```dockerfile
FROM debian:bookworm

# Install MariaDB
RUN apt-get update && apt-get install -y \
    mariadb-server \
    && rm -rf /var/lib/apt/lists/*

# Copy custom configuration
COPY conf/my.cnf /etc/mysql/conf.d/my.cnf

# Copy initialization script
COPY tools/db-setup.sh /usr/local/bin/db-setup.sh
RUN chmod +x /usr/local/bin/db-setup.sh

EXPOSE 3306

# The script creates the DB, users, and then starts mysqld in foreground
ENTRYPOINT ["/usr/local/bin/db-setup.sh"]
```

**conf/my.cnf:**
```ini
[mysqld]
# Listen on all interfaces (necessary for WordPress to connect)
bind-address = 0.0.0.0
# Data directory
datadir = /var/lib/mysql
```

**tools/db-setup.sh:**
```bash
#!/bin/bash
set -e

# Read passwords from secrets (mounted files)
DB_PASSWORD=$(cat /run/secrets/db_password)
DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)

# Initialize MariaDB if it's the first time
if [ ! -d "/var/lib/mysql/mysql" ]; then
    # mariadb-install-db replaces the deprecated mysql_install_db
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql

    # Start temporarily in the background to run setup SQL
    mysqld --user=mysql --skip-networking &
    MYSQL_PID=$!

    # Wait until MariaDB is ready to accept connections
    until mysqladmin ping --silent; do
        sleep 1
    done

    # Run setup SQL using the mysql client (--bootstrap is deprecated in modern MariaDB)
    mysql --user=root <<EOF
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

    # Stop the temporary instance cleanly
    kill $MYSQL_PID
    wait $MYSQL_PID
fi

# Start MariaDB in FOREGROUND (PID 1) — never as a daemon
exec mysqld --user=mysql
```

> The `exec` at the end is crucial — it replaces the script process with mysqld, which becomes PID 1.

> ⚠️ **Why not `--bootstrap`?** The `--bootstrap` flag was deprecated and removed in modern MariaDB versions (10.4+). The correct approach is to start a temporary instance with `--skip-networking` (no external connections allowed), run the setup SQL via the `mysql` client, stop it, and then do the final `exec mysqld` for the real foreground start.

---

### 4.2 WordPress + php-fpm

**What is it?** The website engine. WordPress is the CMS (Content Management System) and php-fpm is the PHP process manager that runs it.

**Why php-fpm and not Apache+PHP?** NGINX cannot execute PHP directly. It needs an intermediary that speaks FastCGI. php-fpm is that intermediary — it listens on port 9000 and processes `.php` files.

**WordPress Dockerfile:**

```dockerfile
FROM debian:bookworm

# Install PHP, php-fpm, and extensions needed for WordPress
RUN apt-get update && apt-get install -y \
    php8.2 \
    php8.2-fpm \
    php8.2-mysql \
    php8.2-curl \
    php8.2-gd \
    php8.2-mbstring \
    php8.2-xml \
    php8.2-zip \
    wget \
    && rm -rf /var/lib/apt/lists/*

# Install WP-CLI (command-line tool for WordPress)
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

# Copy php-fpm configuration
COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf

# Copy setup script
COPY tools/wp-setup.sh /usr/local/bin/wp-setup.sh
RUN chmod +x /usr/local/bin/wp-setup.sh

# Create the directory where WordPress files will go
RUN mkdir -p /var/www/html

WORKDIR /var/www/html

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/wp-setup.sh"]
```

**conf/www.conf** (php-fpm configuration):
```ini
[www]
user = www-data
group = www-data
; Listen on all interfaces on port 9000
listen = 0.0.0.0:9000
listen.owner = www-data
listen.group = www-data
pm = dynamic
pm.max_children = 5
pm.start_servers = 2
pm.min_spare_servers = 1
pm.max_spare_servers = 3
```

**tools/wp-setup.sh:**
```bash
#!/bin/bash
set -e

# Read passwords from secrets (files mounted at /run/secrets/)
DB_PASSWORD=$(cat /run/secrets/db_password)
WP_ADMIN_PASSWORD=$(grep ADMIN_PASS /run/secrets/credentials | cut -d= -f2)
WP_USER_PASSWORD=$(grep WP_USER_PASS /run/secrets/credentials | cut -d= -f2)

# Download WordPress if not already installed
if [ ! -f /var/www/html/wp-config.php ]; then
    # Download WordPress core files
    wp core download --allow-root

    # Create wp-config.php with database connection details
    wp config create \
        --dbname=${MYSQL_DATABASE} \
        --dbuser=${MYSQL_USER} \
        --dbpass=${DB_PASSWORD} \
        --dbhost=mariadb \
        --allow-root

    # Install WordPress (creates tables and sets up the site)
    wp core install \
        --url=https://${DOMAIN_NAME} \
        --title="Inception" \
        --admin_user=${WP_ADMIN_USER} \
        --admin_password=${WP_ADMIN_PASSWORD} \
        --admin_email=${WP_ADMIN_EMAIL} \
        --skip-email \
        --allow-root

    # Create a second non-admin user — required by the subject
    wp user create \
        ${WP_USER} ${WP_USER_EMAIL} \
        --role=author \
        --user_pass=${WP_USER_PASSWORD} \
        --allow-root
fi

# Start php-fpm in FOREGROUND — never as a daemon
exec php-fpm8.2 -F
```

> The `-F` in `php-fpm8.2 -F` means foreground. Without it, php-fpm backgrounds itself and the container dies.

---

### 4.3 NGINX

**What is it?** The web server that acts as the single entry point. It handles TLS and routes PHP requests to WordPress.

**NGINX Dockerfile:**

```dockerfile
FROM debian:bookworm

# Install nginx and openssl (to generate the certificate)
RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    && rm -rf /var/lib/apt/lists/*

# ARG is available at build time (unlike ENV variables from .env which are runtime only)
# Pass it with: docker build --build-arg DOMAIN_NAME=login.42.fr
# Or define it in docker-compose.yml under build.args
ARG DOMAIN_NAME=localhost

# Generate a self-signed TLS certificate using the build-time ARG
RUN openssl req -x509 -newkey rsa:4096 \
    -keyout /etc/ssl/private/nginx.key \
    -out /etc/ssl/certs/nginx.crt \
    -days 365 \
    -nodes \
    -subj "/C=ES/ST=Madrid/O=42/CN=${DOMAIN_NAME}"

# Copy nginx configuration
COPY conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

# Start nginx in FOREGROUND — daemon off is mandatory
CMD ["nginx", "-g", "daemon off;"]
```

> ⚠️ **Why `ARG` and not `ENV`?** Variables from `.env` and `env_file` are only available at **runtime** (when the container runs). They are NOT available during `docker build`. To use a variable during the build (like in a `RUN` command), you need `ARG`. Define it in `docker-compose.yml` under `build.args` so it picks up the value from `.env`:

```yaml
# In docker-compose.yml, under the nginx service:
nginx:
  build:
    context: ./requirements/nginx
    args:
      DOMAIN_NAME: ${DOMAIN_NAME}   # reads from .env at compose time
```

**conf/nginx.conf:**
```nginx
events {
    worker_connections 1024;
}

http {
    include       /etc/nginx/mime.types;
    default_type  application/octet-stream;

    server {
        # Only port 443 with SSL — required by the subject
        listen 443 ssl;
        listen [::]:443 ssl;

        server_name login.42.fr;  # replace with your login

        # Certificate generated in the Dockerfile
        ssl_certificate     /etc/ssl/certs/nginx.crt;
        ssl_certificate_key /etc/ssl/private/nginx.key;

        # Only TLS 1.2 and 1.3 — mandatory in the subject
        ssl_protocols TLSv1.2 TLSv1.3;

        # WordPress files directory (shared volume)
        root /var/www/html;
        index index.php index.html;

        location / {
            try_files $uri $uri/ /index.php?$args;
        }

        # Route PHP requests to WordPress+php-fpm
        location ~ \.php$ {
            fastcgi_split_path_info ^(.+\.php)(/.+)$;
            # "wordpress" is the service name in the Docker network
            fastcgi_pass wordpress:9000;
            fastcgi_index index.php;
            include fastcgi_params;
            fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
            fastcgi_param PATH_INFO $fastcgi_path_info;
        }

        # Block access to hidden files
        location ~ /\.ht {
            deny all;
        }
    }
}
```

---

## Phase 5: Security and Configuration

### The .env File

```bash
# srcs/.env
# Domain
DOMAIN_NAME=login.42.fr

# MariaDB
MYSQL_DATABASE=wordpress
MYSQL_USER=wpuser

# WordPress
WP_ADMIN_USER=supervisor       # ⚠️ cannot contain admin/administrator
WP_ADMIN_EMAIL=supervisor@login.42.fr
WP_USER=reader
WP_USER_EMAIL=reader@login.42.fr
# WP_USER_PASSWORD is read from secrets/credentials.txt — NOT here
```

> Passwords do NOT go in .env — they go in secrets/.

### The Secrets Files

```bash
# secrets/db_password.txt
m1_s3cur3_p4ssw0rd

# secrets/db_root_password.txt
r00t_s3cur3_p4ssw0rd

# secrets/credentials.txt
# Both passwords on separate lines, key=value format
ADMIN_PASS=wp_4dm1n_p4ssw0rd
WP_USER_PASS=us3r_p4ssw0rd
```

And in **wp-setup.sh**, both passwords are read from this file:

```bash
WP_ADMIN_PASSWORD=$(grep ADMIN_PASS /run/secrets/credentials | cut -d= -f2)
WP_USER_PASSWORD=$(grep WP_USER_PASS /run/secrets/credentials | cut -d= -f2)
```

### Why Separate .env from Secrets?

```
.env            → configuration variables (domain, names, users)
                  less sensitive, practical for development

secrets/        → passwords and critical data
                  mounted as files in /run/secrets/ inside the container
                  NEVER visible in environment variables
```

> Both are in `.gitignore`. The difference is conceptual and for defense‑in‑depth security.

### WordPress Users — Important Rule

The subject requires two users and forbids certain names for the administrator:

```
✗ admin, Admin, ADMIN
✗ administrator, Administrator, ADMINISTRATOR
✗ admin-123, admin_wp, myadmin (any variation containing "admin")

✓ supervisor, wpmaster, manager, webmaster, root_user...
```

---

## Phase 6: Docker Network

### What needs to be done?
Create a private network that connects the three containers.

### ⚠️ How NOT to Do It

```bash
# INCORRECT — do not create the network manually
docker network create inception-network
```

### ✓ How to Do It Correctly

The network is defined **inside `docker-compose.yml`** and Docker Compose creates it automatically:

```yaml
networks:
  inception:
    driver: bridge
```

And each service connects to it:
```yaml
services:
  nginx:
    networks:
      - inception
  wordpress:
    networks:
      - inception
  mariadb:
    networks:
      - inception
```

### What is the bridge Driver?

The `bridge` driver creates a private virtual network on the host. Connected containers can communicate with each other by name, but are isolated from the outside.

```
Host
┌──────────────────────────────────────┐
│  Bridge network "inception"          │
│  ┌─────────┐ ┌───────────┐ ┌──────┐ │
│  │  nginx  │ │ wordpress │ │  db  │ │
│  └────┬────┘ └─────┬─────┘ └──┬───┘ │
│       └────────────┴──────────┘      │
└──────────────────────────────────────┘
         ▲
    Only port 443
    exposed to the outside
```

---

## Phase 7: Data Persistence

### What needs to be done?
Define the two mandatory volumes so that data survives restarts.

### The Two Volumes

**wp_data** — WordPress files
- Mounted at `/var/www/html` in the nginx and wordpress containers
- Contains all PHP files, plugins, themes, and images of WordPress
- Shared between nginx (which serves static files) and wordpress (which executes PHP)

**db_data** — MariaDB database
- Mounted at `/var/lib/mysql` in the mariadb container
- Contains all tables, records, and DB configuration
- Only accessed by the mariadb container

### Definition in docker-compose.yml

```yaml
volumes:
  wp_data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/login/data/wordpress   # folder on the host

  db_data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/login/data/mariadb
```

> Replace `login` with your 42 login in both paths.

### Volumes vs Bind Mounts

|                      | Docker Volumes       | Bind Mounts                     |
|----------------------|----------------------|---------------------------------|
| **Management**       | Docker manages them  | You define the host path        |
| **Portability**      | High                 | Low (depends on the path)       |
| **In Inception**     | Technically bind mounts with local driver | That's what the subject defines |
| **Backup**           | `docker volume` commands | Directly on the host           |

---

## Phase 8: Complete docker-compose.yml

The file that brings all the pieces together:

```yaml
services:

  # ── NGINX ──────────────────────────────────────────────
  nginx:
    build:
      context: ./requirements/nginx
      args:
        DOMAIN_NAME: ${DOMAIN_NAME}   # passes .env value as build ARG
    container_name: nginx
    ports:
      - "443:443"
    volumes:
      - wp_data:/var/www/html
    networks:
      - inception
    restart: always
    depends_on:
      - wordpress

  # ── WORDPRESS ──────────────────────────────────────────
  wordpress:
    build: ./requirements/wordpress
    container_name: wordpress
    env_file: .env          # path is relative to docker-compose.yml location (srcs/)
    secrets:
      - db_password
      - credentials
    volumes:
      - wp_data:/var/www/html
    networks:
      - inception
    restart: always
    depends_on:
      - mariadb

  # ── MARIADB ────────────────────────────────────────────
  mariadb:
    build: ./requirements/mariadb
    container_name: mariadb
    env_file: .env          # path is relative to docker-compose.yml location (srcs/)
    secrets:
      - db_password
      - db_root_password
    volumes:
      - db_data:/var/lib/mysql
    networks:
      - inception
    restart: always

# ── SECRETS ────────────────────────────────────────────────
# Paths are relative to docker-compose.yml which lives in srcs/
# secrets/ is at the same level as srcs/, so the path goes up one level
secrets:
  db_password:
    file: ../secrets/db_password.txt
  db_root_password:
    file: ../secrets/db_root_password.txt
  credentials:
    file: ../secrets/credentials.txt

# ── VOLUMES ──────────────────────────────────────────────
volumes:
  wp_data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/login/data/wordpress

  db_data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/login/data/mariadb

# ── NETWORK ────────────────────────────────────────────────────
networks:
  inception:
    driver: bridge
```

> ⚠️ **Path rules in docker-compose.yml:**
> - `env_file: .env` → relative to the `docker-compose.yml` file itself (in `srcs/`) → correct ✓
> - `file: ../secrets/db_password.txt` → goes up one level from `srcs/` to reach `secrets/` → correct ✓
> - The Makefile runs `docker compose -f srcs/docker-compose.yml`, so Docker Compose's working directory is `srcs/`

---

## Phase 9: Makefile

The Makefile must be at the root and must build and launch everything:

```makefile
# Replace login with your 42 login
LOGIN = login
DATA_PATH = /home/$(LOGIN)/data

all: up

# Create data directories and bring everything up
up:
	@mkdir -p $(DATA_PATH)/wordpress $(DATA_PATH)/mariadb
	@docker compose -f srcs/docker-compose.yml up --build -d

# Stop containers
down:
	@docker compose -f srcs/docker-compose.yml down

# Stop and remove everything (containers, images, volumes)
clean: down
	@docker compose -f srcs/docker-compose.yml down --rmi all --volumes

# Full clean — also remove persistent data
fclean: clean
	@sudo rm -rf $(DATA_PATH)

# Rebuild everything from scratch
re: fclean all

# View logs of all services
logs:
	@docker compose -f srcs/docker-compose.yml logs -f

# Container status
ps:
	@docker compose -f srcs/docker-compose.yml ps

.PHONY: all up down clean fclean re logs ps
```

---

## Phase 10: Testing and Validation

### Essential Verification Commands

```bash
# 1. Bring up the infrastructure
make

# 2. Check that all 3 containers are running
docker ps

# 3. View logs in real time (useful for debugging)
docker logs nginx
docker logs wordpress
docker logs mariadb

# 4. Access the website
# Open your browser at: https://login.42.fr
# (Accept the self-signed certificate warning)

# 5. Verify TLS
openssl s_client -connect login.42.fr:443 -tls1_2
openssl s_client -connect login.42.fr:443 -tls1_3

# 6. Verify that the DB has the correct users
docker exec -it mariadb mysql -u root -p
# Inside MySQL:
# SELECT User, Host FROM mysql.user;
# SHOW DATABASES;

# 7. Verify that volumes persist
docker compose down
docker compose up -d
# Data should still be there
```

### Validation Checklist

```
□ https://login.42.fr loads WordPress correctly
□ The TLS certificate is valid (even if self‑signed)
□ TLSv1.2 and TLSv1.3 work, older versions are rejected
□ The WordPress admin panel is accessible at /wp-admin
□ Exactly 2 users exist in WordPress
□ The admin username does NOT contain "admin" or "administrator"
□ Data persists after docker compose down && up
□ If you kill a container, it restarts automatically
□ MariaDB is NOT accessible from outside the container
□ WordPress is NOT directly accessible from outside
□ No passwords in any Dockerfile
□ No passwords in docker-compose.yml
□ secrets/ is in .gitignore
□ srcs/.env is in .gitignore
```

---

## Phase 11: Documentation

### README.md — Minimum Required Structure

```markdown
*This project has been created as part of the 42 curriculum by login.*

## Description
[What the project is and its objective]

## Instructions
[How to install and run]

## Project Description
[Use of Docker, architecture design]

### Virtual Machines vs Docker
[Comparison]

### Secrets vs Environment Variables
[Comparison]

### Docker Network vs Host Network
[Comparison]

### Docker Volumes vs Bind Mounts
[Comparison]

## Resources
[Documentation, articles, tutorials]
[How AI was used and for which parts]
```

### USER_DOC.md — For the End User

```markdown
# User Documentation

## What services does this stack offer?
- WordPress: website accessible at https://login.42.fr
- MariaDB: database (internal access only)

## How to start the project
make

## How to stop the project
make down

## How to access the site
https://login.42.fr

## How to access the admin panel
https://login.42.fr/wp-admin

## Where are the credentials?
secrets/credentials.txt

## Verify that services are running
docker ps
```

### DEV_DOC.md — For the Developer

```markdown
# Developer Documentation

## Prerequisites
- VirtualBox or similar
- Docker and Docker Compose installed
- Port 443 free

## Setup from scratch
1. Clone the repository
2. Create secrets/ with the passwords
3. Configure srcs/.env with your login
4. Add login.42.fr to /etc/hosts
5. Create data directories: mkdir -p /home/login/data/{wordpress,mariadb}

## Build and launch
make

## Useful commands
make logs    # view logs
make ps      # container status
make clean   # clean everything
make fclean  # clean including data

## Where data is stored
/home/login/data/wordpress  ← WordPress files
/home/login/data/mariadb    ← database
```

---

## Phase 12: Bonus

Bonus is evaluated **only if the mandatory part works perfectly**.

Each bonus needs its own Dockerfile (built from Alpine/Debian, not from pre‑built images) and, if applicable, its own volume.

### Redis — Cache for WordPress

```dockerfile
FROM debian:bookworm
RUN apt-get update && apt-get install -y redis-server
CMD ["redis-server", "--daemonize", "no"]   # foreground
```

In WordPress you need to install the `Redis Object Cache` plugin and configure it.

### FTP Server

```dockerfile
FROM debian:bookworm
RUN apt-get update && apt-get install -y vsftpd
COPY conf/vsftpd.conf /etc/vsftpd.conf
CMD ["vsftpd", "/etc/vsftpd.conf"]
```

It must point to the WordPress volume (`/home/login/data/wordpress`).

### Static Website (not PHP)

It can be pure HTML, Python, Go, Node.js — anything except PHP.

```dockerfile
FROM debian:bookworm
RUN apt-get update && apt-get install -y nginx
COPY html/ /var/www/html/
COPY conf/nginx.conf /etc/nginx/nginx.conf
CMD ["nginx", "-g", "daemon off;"]
```

### Adminer

Web‑based database manager. It's installed as a single PHP file.

### Free Choice Service

Any service you can justify during the defense. Examples:
- Portainer (graphical interface for Docker)
- Grafana + Prometheus (monitoring)
- Netdata (system metrics)

---

## Preparation for the Defense

During the evaluation, you may be asked for a **live modification**. Make sure you understand every line of your code.

### Frequently Asked Questions in the Defense

```
Why are you using Debian and not Alpine?
What exactly does the MariaDB initialization script do?
Why php-fpm instead of Apache?
What happens if you kill the WordPress container?
Where is data stored when you do docker compose down?
Why can't the admin username contain "admin"?
What's the difference between a secret and an environment variable?
Why is NGINX the only entry point?
What is PID 1 and why does it matter?
What does daemon off do in NGINX?
Why can't you use :latest?
```