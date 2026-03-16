#### **Phase 1: Setup and Environment**
- **Task**: Create a virtual machine (VM) or use a cloud environment.
- **Action**: Install Docker, clone the repository, and set up the project directory.
- **Tip**: Use a `.dockerignore` file to exclude sensitive files from Git.

#### **Phase 2: Directory Structure**
- **Task**: Organize the project into the required directory structure.
- **Action**: Create `srcs/`, `secrets/`, `requirements/`, and `.env`.
- **Tip**: Follow the example in the document (e.g., `srcs/requirements/mariadb/`).

#### **Phase 3: Base Docker Images**
- **Task**: Pull required base images (e.g., `php:8.2-alpine`, `mariadb:10.8`, `nginx:alpine`).
- **Action**: Use `Dockerfile` and `.dockerignore` to define base layers.

#### **Phase 4: Mandatory Services**
- **Task**: Configure Docker containers for NGINX, WordPress, and MariaDB.
- **Action**:
  - Create `Dockerfile` for each service.
  - Define volumes, ports, and environment variables in `docker-compose.yml`.
- **Tip**: Use `docker-compose` to manage multi-container setups.

#### **Phase 5: Security Configuration**
- **Task**: Secure the infrastructure using environment variables and secrets.
- **Action**:
  - Store credentials in `secrets/` (ignored by Git).
  - Use `.env` for domain and configuration.
  - Configure TLS for NGINX.

#### **Phase 6: Networking**
- **Task**: Set up a Docker network for container communication.
- **Action**:
  - Create a custom Docker network (e.g., `docker network create inception-network`).
  - Link containers to the network in `docker-compose.yml`.

#### **Phase 7: Data Persistence**
- **Task**: Ensure data persistence using Docker volumes.
- **Action**:
  - Define volumes in `docker-compose.yml` for WordPress and MariaDB.
  - Use named volumes (e.g., `wordpress_data`) for persistence.

#### **Phase 8: Testing and Validation**
- **Task**: Test the infrastructure for functionality and security.
- **Action**:
  - Run `docker compose up` and verify services (e.g., access WordPress via the domain).
  - Check TLS configuration and database connectivity.

#### **Phase 9: Documentation**
- **Task**: Write required documentation files.
- **Action**:
  - Create `README.md`, `USER_DOC.md`, and `DEV_DOC.md`.
  - Include sections on Docker, architecture, and AI usage.

#### **Phase 10: Bonus and Defense Prep**
- **Task**: Add bonus services and prepare for evaluation.
- **Action**:
  - Implement bonus tasks (e.g., Adminer, Redis).
  - Practice explaining design choices (e.g., why use secrets over environment variables).

---

### **Key Tips for Success**
- **Security**: Never hardcode credentials. Use `.env` and GitIgnore.
- **Dockerfile Best Practices**: Keep base images minimal (e.g., `php:8.2-alpine`).
- **Documentation**: Clearly explain architecture, Docker, and AI usage in `README.md`.
- **Defense Prep**: Be ready to justify technical choices (e.g., why use TLS or Docker volumes).
