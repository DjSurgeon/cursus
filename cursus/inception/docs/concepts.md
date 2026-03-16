# Inception — Comprehensive Study Guide

> A complete guide to understanding and implementing the 42 project Inception, based on study sessions and official subject requirements.

---

## Index

1. [Project Context](#project-context)
2. [What is Docker?](#what-is-docker)
3. [Image vs Container](#image-vs-container)
4. [Dockerfile](#dockerfile)
5. [Volumes](#volumes)
6. [Docker Networks](#docker-networks)
7. [PID 1 and Daemons](#pid-1-and-daemons)
8. [HTTPS and TLS](#https-and-tls)
9. [Environment Variables and Secrets](#environment-variables-and-secrets)
10. [NGINX as Reverse Proxy](#nginx-as-reverse-proxy)
11. [docker-compose.yml](#docker-composeyml)
12. [Restart Policy](#restart-policy)
13. [The Inception Infrastructure](#the-inception-infrastructure)
14. [Critical Subject Rules](#critical-subject-rules)
15. [Expected File Structure](#expected-file-structure)
16. [Mandatory Documentation](#mandatory-documentation)
17. [Bonus](#bonus)

---

## Project Context

The Inception project must be developed inside a **virtual machine** (VM) as required by the 42 curriculum. For example, you might use a VM with Ubuntu and allocate at least 20 GB of disk space. All Docker containers will run inside this VM, ensuring isolation and reproducibility.

---

## What is Docker?

Docker solves the classic "it works on my machine" problem by packaging an application together with **everything it needs** (libraries, configuration, dependencies) into a unit called a **container**. Containers run in isolated environments but share the kernel of the host system.

Compared to virtual machines, containers are much lighter because they do not require a full operating system per service.

---

## Image vs Container

| Concept      | Description                                                      | Analogy                     |
|--------------|------------------------------------------------------------------|-----------------------------|
| **Dockerfile** | File with instructions to build an image                         | Source code of a class      |
| **Image**      | Immutable template resulting from `docker build`                 | Compiled class              |
| **Container**  | Running instance of an image — a live, isolated process          | Instantiated object         |

```
Dockerfile  →  (docker build)  →  Image  →  (docker run)  →  Container
```

- From one image you can create **multiple containers**.
- The image **never changes** when the container writes data.
- A container is **ephemeral** — its data disappears when it stops (that’s why we use volumes).

---

## Dockerfile

A text file with instructions that Docker executes from top to bottom to build an image, **layer by layer**.

```dockerfile
# Base image — starting point
FROM debian:bookworm

# Run commands during build
RUN apt-get update && apt-get install -y nginx openssl

# Generate a self‑signed TLS certificate
RUN openssl req -x509 -newkey rsa:4096 \
    -keyout /etc/ssl/private/key.pem \
    -out /etc/ssl/certs/cert.pem \
    -days 365 -nodes \
    -subj "/CN=login.42.fr"

# Copy files from your host into the container
COPY conf/nginx.conf /etc/nginx/nginx.conf

# Document which port the container uses
EXPOSE 443

# Command that runs when the container starts
CMD ["nginx", "-g", "daemon off;"]
```

**Layers and caching:** Each `RUN`, `COPY`, or `ADD` instruction creates a layer. Docker caches layers — if you only change your `nginx.conf`, it won’t reinstall the whole Debian base.

**Subject rules:**
- One Dockerfile per service (nginx, wordpress, mariadb).
- You **may not** use pre‑built images from Docker Hub (Alpine and Debian base images are allowed).
- The `:latest` tag is forbidden — use specific versions like `debian:bookworm`.
- **No passwords** may appear in the Dockerfile.

---

## Volumes

Containers are **ephemeral** — any data written inside their filesystem disappears when the container stops. Volumes are storage areas **external to the container** that persist even if the container is destroyed and recreated.

```
Without volume:                 With volume:
┌──────────────┐                 ┌──────────────┐
│  Container   │                 │  Container   │──── Volume ────┐
│  /var/lib/   │ ← gets deleted  │  /var/lib/   │                │
│  mysql/      │   when stopped  │  mysql/      │           ┌────┴────┐
└──────────────┘                 └──────────────┘           │  data   │
                                                            │ persists│
                                                            └─────────┘
```

**In Inception you need two volumes:**
- `wp_data` → WordPress files (`/var/www/html`)
- `db_data` → MariaDB database (`/var/lib/mysql`)

The `wp_data` volume is **shared** between NGINX and WordPress — both need access to the PHP files.

These volumes must be available on the host at `/home/login/data` (replace `login` with your 42 login).

---

## Docker Networks

By default, containers are **completely isolated** from each other. A Docker network allows them to communicate using their **service names as hostnames** — you don’t need to know IP addresses.

```yaml
networks:
  inception:
    driver: bridge
```

With all services on the same `inception` network, WordPress can connect to MariaDB simply by using `mariadb` as the hostname:

```
WordPress → "connect to mariadb:3306" → Docker resolves → MariaDB container
```

**Forbidden by the subject:**
- `network: host` — the container shares the host’s network, breaking isolation.
- `--link` and `links:` — old, deprecated mechanisms.

---

## PID 1 and Daemons

### PID 1
In Linux, the process with **PID 1** is the parent of all processes. It has special responsibilities: receiving system signals, reaping orphaned processes, and shutting down cleanly.

In Docker, **the process you launch in the container becomes PID 1**. If that process dies, Docker kills the container.

### Daemons
A **daemon** is a process that runs in the background. In a normal Linux environment this is fine, but in Docker it’s a problem: if your process backgrounds itself, Docker thinks it has finished and **terminates the container**.

**Solution: run services in the foreground:**

```dockerfile
# BAD — nginx goes to background, container dies
CMD ["nginx"]

# GOOD — nginx stays in foreground as PID 1, container stays alive
CMD ["nginx", "-g", "daemon off;"]
```

**Forbidden hacks** (artificial ways to keep a container alive):
```bash
tail -f /dev/null
sleep infinity
while true; do :; done
bash
```

**How to run each service in the foreground:**
- NGINX: `nginx -g "daemon off;"`
- php‑fpm: `php-fpm8.2 -F` (the `-F` flag keeps it in foreground)
- MariaDB: `mysqld` (already runs in foreground by default)

---

## HTTPS and TLS

**HTTP** sends data in plain text — anyone intercepting the traffic can read it.

**HTTPS = HTTP + TLS** — data is encrypted.

```
HTTP:   browser → "password=1234" → server    ← readable
HTTPS:  browser → "x7#kQ9@mZ..."  → server    ← unreadable without the key
```

**TLS** (Transport Layer Security) is the encryption protocol. The subject requires **TLSv1.2 or TLSv1.3** — older versions have known vulnerabilities.

For HTTPS you need a **certificate**. In Inception you will use a **self‑signed** one generated with openssl:

```bash
openssl req -x509 -newkey rsa:4096 \
    -keyout /etc/ssl/private/key.pem \
    -out /etc/ssl/certs/cert.pem \
    -days 365 -nodes \
    -subj "/CN=login.42.fr"
```

Your browser will warn that the certificate is not trusted (because it wasn’t signed by a recognised CA), but the connection will be encrypted. That’s sufficient for the project.

**TLS configuration in NGINX:**
```nginx
ssl_certificate     /etc/ssl/certs/cert.pem;
ssl_certificate_key /etc/ssl/private/key.pem;
ssl_protocols       TLSv1.2 TLSv1.3;
```

---

## Environment Variables and Secrets

### Environment Variables
Key‑value pairs (`KEY=value`) that live in the process’s memory. Programs inside the container read them automatically.

The **`.env`** file is where you define them — Docker Compose reads it on startup:

```bash
# srcs/.env
DOMAIN_NAME=login.42.fr
MYSQL_DATABASE=wordpress
MYSQL_USER=wpuser
MYSQL_PASSWORD=secret123
MYSQL_ROOT_PASSWORD=rootsecret
```

### Docker Secrets
A more secure mechanism for passwords. The value is mounted as a file in `/run/secrets/<name>`, accessible only by the process that needs it.

|                     | Environment Variables | Docker Secrets            |
|---------------------|-----------------------|---------------------------|
| **Use case**        | General config, names, users | Passwords, API keys       |
| **Visibility**      | Any process in the container | Only the process that needs it |
| **Storage**         | `.env` file           | Files under `secrets/`    |

**Golden rule:** never write a password inside a Dockerfile or `docker-compose.yml` — those files go to Git and would expose credentials → **direct failure** of the project.

---

## NGINX as Reverse Proxy

NGINX acts as the **single doorkeeper** of the infrastructure. All external traffic passes through it.

```
Internet
    │
    ▼ port 443 (HTTPS)
┌─────────────────────┐
│       NGINX         │  ← only entry point
│   (reverse proxy)   │  ← handles TLS
└──────────┬──────────┘  ← routes internally
           │
           │ fastcgi_pass wordpress:9000
           ▼
┌─────────────────────┐
│   WordPress+php-fpm │  ← processes PHP, generates HTML
└──────────┬──────────┘
           │
           │ host: mariadb, port: 3306
           ▼
┌─────────────────────┐
│      MariaDB        │  ← database
└─────────────────────┘
```

**Why a reverse proxy instead of exposing WordPress directly?**
- Only port 443 is open to the outside.
- WordPress and MariaDB are invisible from outside.
- NGINX centralises TLS management, logging, and security.

**nginx.conf configuration:**
```nginx
server {
    listen 443 ssl;
    server_name login.42.fr;

    ssl_certificate     /etc/ssl/certs/cert.pem;
    ssl_certificate_key /etc/ssl/private/key.pem;
    ssl_protocols       TLSv1.2 TLSv1.3;

    root /var/www/html;
    index index.php;

    location / {
        try_files $uri $uri/ /index.php?$args;
    }

    # Route PHP requests to WordPress+php-fpm
    location ~ \.php$ {
        fastcgi_pass wordpress:9000;
        include fastcgi_params;
        fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
    }
}
```

**Why php‑fpm?** NGINX cannot execute PHP directly. `php‑fpm` (FastCGI Process Manager) is the intermediary that processes `.php` files and returns the generated HTML.

---

## docker-compose.yml

A YAML file that defines and orchestrates the entire infrastructure — services, volumes, and networks — in one place.

```bash
docker compose up --build    # build images and start everything
docker compose down          # stop and remove containers
docker compose logs          # view logs of all services
docker compose ps            # see container status
```

**Complete Inception `docker-compose.yml`:**

```yaml
services:

  nginx:
    build: ./requirements/nginx
    container_name: nginx
    ports:
      - "443:443"              # only nginx exposes ports to the host
    volumes:
      - wp_data:/var/www/html
    networks:
      - inception
    restart: always
    depends_on:
      - wordpress

  wordpress:
    build: ./requirements/wordpress
    container_name: wordpress
    env_file: .env
    volumes:
      - wp_data:/var/www/html
    networks:
      - inception
    restart: always
    depends_on:
      - mariadb

  mariadb:
    build: ./requirements/mariadb
    container_name: mariadb
    env_file: .env
    volumes:
      - db_data:/var/lib/mysql
    networks:
      - inception
    restart: always

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

networks:
  inception:
    driver: bridge
```

**Key points:**
- Only NGINX has `ports` — the other services are not exposed to the host.
- `wp_data` is shared between nginx and wordpress.
- `depends_on` defines the startup order.
- `env_file` loads variables from `.env`.

---

## Restart Policy

Defines what Docker does when a container stops.

| Policy           | Behaviour                                      |
|------------------|------------------------------------------------|
| `"no"`           | Never restarts (default)                       |
| `always`         | Always restarts ← **use this in Inception**    |
| `on-failure`     | Restart only if it exited with an error        |
| `unless-stopped` | Always, unless you manually stopped it         |

**Why it matters in Inception:**

MariaDB takes a few seconds to start. WordPress starts, tries to connect, fails, and exits. With `restart: always`, Docker will retry until MariaDB is ready:

```
mariadb starts (takes ~3s to be ready)
wordpress starts → fails to connect → exits
Docker: "wordpress died, restarting it"
wordpress starts again → mariadb is now ready → works ✓
```

---

## The Inception Infrastructure

### Overview

```
                    WWW (Internet)
                         │
                    port 443
                         │
              ┌──────────▼──────────┐
              │    Host Machine     │ (your VM)
              │  ┌───────────────────────────┐
              │  │    Docker network         │
              │  │      "inception"          │
              │  │                           │
              │  │  ┌─────┐  3306  ┌───────┐ │
              │  │  │  DB │◄──────►│  WP   │ │
              │  │  └──┬──┘        │ +PHP  │ │
              │  │     │      9000 └───┬───┘ │
              │  │     │              │      │
              │  │     │         ┌────▼────┐ │
              │  │     │         │  NGINX  │ │
              │  │     │         └─────────┘ │
              │  └─────┼─────────────────────┘
              │        │
              │   ┌────▼────┐  ┌──────────┐
              │   │ Vol. DB │  │ Vol. WP  │
              │   └─────────┘  └──────────┘
              └─────────────────────────────┘
```

### The Three Containers

| Service           | Base Image      | Port      | Role                               |
|-------------------|-----------------|-----------|------------------------------------|
| **NGINX**         | Alpine/Debian   | 443 (host)| Reverse proxy + TLS termination    |
| **WordPress + php‑fpm** | Alpine/Debian | 9000 (internal) | PHP processing, site logic      |
| **MariaDB**       | Alpine/Debian   | 3306 (internal) | Database                          |

### WordPress Requirements
- Two database users: an **administrator** and a **regular user**.
- The administrator’s username **cannot contain**: `admin`, `Admin`, `administrator`, `Administrator` or any variation.
- Domain configured as `login.42.fr` pointing to your local IP (edit `/etc/hosts`).

---

## Critical Subject Rules

```
✗ Pre‑built Docker images from Docker Hub are forbidden (except base OS images)
✗ The :latest tag is forbidden
✗ No passwords in Dockerfiles
✗ network: host, --link, links: are forbidden
✗ No artificial keep‑alive hacks (tail -f, sleep infinity, while true, bash as entrypoint)
✗ Credentials must never be committed to Git → direct failure

✓ One Dockerfile per service is mandatory
✓ Use docker compose
✓ Use environment variables and a .env file
✓ Use Alpine or Debian (penultimate stable version)
✓ restart: always on all services
✓ NGINX must be the only entry point through port 443
✓ TLSv1.2 or TLSv1.3 required
✓ A dedicated Docker network (not host) must be used
✓ Two volumes: one for WordPress files, one for the database
```

---

## Expected File Structure

```
.
├── Makefile
├── secrets/
│   ├── credentials.txt
│   ├── db_password.txt
│   └── db_root_password.txt
└── srcs/
    ├── .env
    ├── docker-compose.yml
    └── requirements/
        ├── nginx/
        │   ├── Dockerfile
        │   ├── conf/
        │   │   └── nginx.conf
        │   └── tools/
        ├── wordpress/
        │   ├── Dockerfile
        │   ├── conf/
        │   └── tools/
        │       └── wp-setup.sh
        └── mariadb/
            ├── Dockerfile
            ├── conf/
            │   └── my.cnf
            └── tools/
                └── db-setup.sh
```

---

## Mandatory Documentation

### README.md
- First line in italics: *This project has been created as part of the 42 curriculum by <login>.*
- **Description** section — project objective.
- **Instructions** section — how to build, install, and run.
- **Resources** section — references and how AI was used.
- **Project description** section with comparisons:

| Comparison        | Concept A         | Concept B          |
|-------------------|-------------------|--------------------|
| Virtualisation    | Virtual Machines  | Docker             |
| Sensitive data    | Secrets           | Environment Variables |
| Connectivity      | Docker Network    | Host Network       |
| Persistence       | Docker Volumes    | Bind Mounts        |

### USER_DOC.md
Documentation for the end user:
- What services the stack provides.
- How to start and stop the project.
- How to access the website and the admin panel.
- Where credentials are stored and how to manage them.
- How to verify that the services are running.

### DEV_DOC.md
Documentation for developers:
- Setting up the environment from scratch (prerequisites, configuration files, secrets).
- Building and launching with Makefile and Docker Compose.
- Useful commands for managing containers and volumes.
- Where data is stored and how it persists.

---

## Bonus

Bonus features are evaluated **only if the mandatory part is perfectly done**.

| Service         | Description                                      |
|-----------------|--------------------------------------------------|
| **Redis**       | Cache for WordPress                              |
| **FTP Server**  | Points to the WordPress volume                   |
| **Static website** | In any language except PHP                     |
| **Adminer**     | Web‑based database management tool               |
| **Free choice** | Any service you can justify                      |

Each bonus service needs its own Dockerfile and, if necessary, its own volume.
