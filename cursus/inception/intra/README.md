*This project has been created as part of the 42 curriculum by serjimen.*

# 🐳 Inception - System Administration with Docker

## Description
**Inception** is a foundational infrastructure project at 42. The primary goal is to broaden knowledge of system administration by deploying a robust, multi-container web architecture utilizing Docker.

This infrastructure orchestrates three independent services built from scratch on Alpine Linux:
- **NGINX:** The sole entry point to the infrastructure, strictly handling HTTPS requests via TLSv1.2 and TLSv1.3.
- **WordPress:** The main application layer, running alongside PHP-FPM to process dynamic content.
- **MariaDB:** The backend relational database management system.

The project strictly adheres to the principles of Infrastructure as Code (IaC) and containerization best practices, avoiding the use of pre-built images or process manager hacks.

## Instructions
To build and execute the project:
1. Ensure the local domain resolves to the host machine. Modify your `/etc/hosts` to include: `127.0.0.1 serjimen.42.fr`
2. Navigate to the root directory of the repository where the `Makefile` resides.
3. Deploy the entire infrastructure by executing: `make up`
4. The application will be securely accessible at `https://serjimen.42.fr`.

## Project Description
This project fundamentally relies on **Docker** for service orchestration, guaranteeing isolation, reproducibility, and minimal overhead. Each service is built from a minimal Alpine base image, ensuring a lightweight footprint and a reduced attack surface.

### Technical Comparisons & Design Choices

#### Virtual Machines vs Docker
Virtual Machines (VMs) emulate entire hardware stacks, running a full guest Operating System (OS) for each instance, which incurs significant overhead in terms of CPU, RAM, and disk space. In contrast, Docker utilizes containerization technology. Containers share the host OS kernel and isolate application processes natively via namespaces and cgroups. This design choice makes Docker substantially more lightweight, faster to instantiate, and less resource-intensive.

#### Secrets vs Environment Variables
Environment variables (`.env`) are suitable for non-sensitive configuration data (e.g., domain names, service ports) but are inherently insecure for sensitive credentials, as they can be easily exposed via `docker inspect` or leaked in process logs. Docker Secrets mitigate this risk by securely transmitting confidential data directly into a temporary file system (`/run/secrets/`) within the container, preventing exposure during image builds or runtime introspection. 

#### Docker Network vs Host Network
Using the host network maps container ports directly to the host's network interfaces, removing network isolation and increasing the risk of port collisions and security vulnerabilities. This project implements a custom bridged Docker network (`inception`). This design choice provides a secure, isolated sub-network where services can communicate internally via DNS resolution (e.g., WordPress connecting to MariaDB), while only explicitly exposing the NGINX port (443) to the external host network.

#### Docker Volumes vs Bind Mounts
Docker Volumes are storage mechanisms completely managed by Docker, typically stored within `/var/lib/docker/volumes/`, offering seamless integration and abstraction. However, this project mandates the use of Bind Mounts, linking specific directories on the host filesystem (`/home/serjimen/data/...`) directly to paths inside the containers. This ensures that critical database and application data persists transparently on the host machine, independent of container lifecycle, while granting direct access to the files from the host OS.

## Resources
The development of this project relied on official documentation and community standards:
- Docker Documentation: https://docs.docker.com/
- Alpine Linux Wiki: https://wiki.alpinelinux.org/
- NGINX Official Documentation: https://nginx.org/en/docs/
- MariaDB Server Documentation: https://mariadb.com/kb/en/
- PHP-FPM Configuration Guides.

### AI Usage
AI tooling (Gemini CLI) was utilized as an auxiliary pair-programming tool for:
- **Optimization:** Assisting in the formulation of high-performance Dockerfile instructions and shell script syntax.
- **Documentation:** Providing structural feedback and proofreading for markdown formatting in `README.md`, `DEV_DOC.md`, and `USER_DOC.md`.
