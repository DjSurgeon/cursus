#!/bin/bash
# =============================================================================
# Inception — Setup Script v2
# Uso: bash setup.sh <tu_login_de_42>
# =============================================================================

# NO usamos set -e global — manejamos errores por sección
LOGIN=$1

# ── Colores para output ───────────────────────────────────────────────────────
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

ok()   { echo -e "${GREEN}[OK]${NC} $1"; }
warn() { echo -e "${YELLOW}[WARN]${NC} $1"; }
fail() { echo -e "${RED}[FAIL]${NC} $1"; }

# ── Validación de argumentos ──────────────────────────────────────────────────
if [ -z "$LOGIN" ]; then
    fail "Debes pasar tu login de 42 como argumento"
    echo "Uso: bash setup.sh <login>"
    exit 1
fi

echo "========================================"
echo " Inception Setup v2 — login: $LOGIN"
echo "========================================"

# =============================================================================
# PASO 1 — Actualizar el sistema
# # =============================================================================
# echo ""
# echo "[1/7] Actualizando el sistema..."
# if sudo apt-get update -y && sudo apt-get upgrade -y; then
#     ok "Sistema actualizado"
# else
#     warn "Actualización con errores — continuando igualmente"
# fi

# # =============================================================================
# # PASO 2 — Herramientas básicas
# # =============================================================================
# echo ""
# echo "[2/7] Instalando herramientas básicas..."
# if sudo apt-get install -y curl wget git vim make ca-certificates gnupg; then
#     ok "Herramientas básicas instaladas"
# else
#     fail "Error instalando herramientas básicas"
#     exit 1  # Esto sí es crítico — sin curl no podemos seguir
# fi

# # =============================================================================
# # PASO 3 — Docker
# # Estrategia: intentamos el método oficial primero.
# # Si falla, instalamos Docker Compose manualmente como binario.
# # =============================================================================
# echo ""
# echo "[3/7] Instalando Docker..."

# # Añadir GPG key y repositorio (esto no suele fallar)
# sudo install -m 0755 -d /etc/apt/keyrings
# curl -fsSL https://download.docker.com/linux/ubuntu/gpg | \
#     sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg 2>/dev/null
# sudo chmod a+r /etc/apt/keyrings/docker.gpg

# echo "deb [arch=$(dpkg --print-architecture) \
#     signed-by=/etc/apt/keyrings/docker.gpg] \
#     https://download.docker.com/linux/ubuntu \
#     $(. /etc/os-release && echo "$VERSION_CODENAME") stable" | \
#     sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

# sudo apt-get update -y

# # Intentar instalar todo junto
# if sudo apt-get install -y docker-ce docker-ce-cli containerd.io docker-compose-plugin 2>/dev/null; then
#     ok "Docker instalado via apt (método oficial)"
# else
#     warn "Fallo con docker-compose-plugin — instalando Docker sin el plugin..."

#     # Limpiar estado roto de dpkg
#     sudo dpkg --configure -a 2>/dev/null
#     sudo apt-get install -f -y 2>/dev/null

#     # Instalar solo el motor de Docker
#     sudo apt-get install -y docker-ce docker-ce-cli containerd.io

#     # Instalar Docker Compose manualmente como binario
#     warn "Instalando Docker Compose como binario independiente..."
#     COMPOSE_VERSION=$(curl -s https://api.github.com/repos/docker/compose/releases/latest \
#         | grep '"tag_name"' | cut -d'"' -f4)

#     sudo mkdir -p /usr/local/lib/docker/cli-plugins
#     sudo curl -SL \
#         "https://github.com/docker/compose/releases/download/${COMPOSE_VERSION}/docker-compose-linux-x86_64" \
#         -o /usr/local/lib/docker/cli-plugins/docker-compose
#     sudo chmod +x /usr/local/lib/docker/cli-plugins/docker-compose
# fi

# # Verificar que Docker quedó operativo — esto sí falla el script si no está
# if docker --version > /dev/null 2>&1; then
#     ok "Docker: $(docker --version)"
# else
#     fail "Docker no quedó instalado correctamente — abortando"
#     exit 1
# fi

# if docker compose version > /dev/null 2>&1; then
#     ok "Docker Compose: $(docker compose version)"
# else
#     fail "Docker Compose no quedó instalado — abortando"
#     exit 1
# fi

# # Añadir usuario al grupo docker
# sudo usermod -aG docker "$LOGIN"
# ok "Usuario $LOGIN añadido al grupo docker"

# =============================================================================
# PASO 4 — Directorios de datos para volúmenes
# =============================================================================
echo ""
echo "[4/7] Creando directorios de datos..."
mkdir -p /home/"$LOGIN"/data/wordpress
mkdir -p /home/"$LOGIN"/data/mariadb
ok "Directorios de datos creados en /home/$LOGIN/data/"

# =============================================================================
# PASO 5 — /etc/hosts
# =============================================================================
echo ""
echo "[5/7] Configurando dominio local..."
DOMAIN="${LOGIN}.42.fr"

if grep -q "$DOMAIN" /etc/hosts; then
    warn "Dominio $DOMAIN ya existe en /etc/hosts — omitiendo"
else
    echo "127.0.0.1    $DOMAIN" | sudo tee -a /etc/hosts > /dev/null
    ok "Dominio $DOMAIN añadido a /etc/hosts"
fi

# =============================================================================
# PASO 6 — Estructura del proyecto
# =============================================================================
echo ""
echo "[6/7] Creando estructura del proyecto..."
cd /home/"$LOGIN"

mkdir -p srcs/requirements/nginx/{conf,tools}
mkdir -p srcs/requirements/wordpress/{conf,tools}
mkdir -p srcs/requirements/mariadb/{conf,tools}
mkdir -p secrets
ok "Directorios del proyecto creados"

touch Makefile
touch srcs/docker-compose.yml
ok "Archivos base creados"

# .gitignore
cat > /home/"$LOGIN"/.gitignore << EOF
# Secrets — NEVER in the repository
secrets/
srcs/.env

# Volume data
/home/*/data/

# System files
.DS_Store
*.swp
*~
EOF
ok ".gitignore creado"

# .env
cat > /home/"$LOGIN"/srcs/.env << EOF
# Domain
DOMAIN_NAME=${LOGIN}.42.fr

# MariaDB
MYSQL_DATABASE=wordpress
MYSQL_USER=wpuser

# WordPress users
WP_ADMIN_USER=supervisor
WP_ADMIN_EMAIL=supervisor@${LOGIN}.42.fr
WP_USER=reader
WP_USER_EMAIL=reader@${LOGIN}.42.fr
EOF
ok "srcs/.env creado"

# Secrets con placeholders
echo "CHANGEME_wp_db_password" > /home/"$LOGIN"/secrets/db_password.txt
echo "CHANGEME_root_password"  > /home/"$LOGIN"/secrets/db_root_password.txt
cat > /home/"$LOGIN"/secrets/credentials.txt << EOF
ADMIN_PASS=CHANGEME_admin_pass
WP_USER_PASS=CHANGEME_user_pass
EOF
ok "Archivos de secrets creados (con placeholders — recuerda cambiarlos)"

# =============================================================================
# PASO 7 — Verificación final
# =============================================================================
echo ""
echo "[7/7] Verificación final..."
echo ""
echo "── Docker ──────────────────────────────────────"
docker --version
docker compose version

echo ""
echo "── Directorios de datos ────────────────────────"
ls -la /home/"$LOGIN"/data/

echo ""
echo "── Estructura del proyecto ─────────────────────"
find /home/"$LOGIN" \
    -not -path '*/.git/*' \
    -not -path '*/data/*' \
    -not -path '*/.cache/*' \
    -not -path '*/.ssh/*' \
    -not -name '.bash*' \
    -not -name '.profile' \
    | sort

echo ""
echo "── /etc/hosts ──────────────────────────────────"
grep "42.fr" /etc/hosts

echo ""
echo "========================================"
echo -e "${GREEN} Setup completado para: $LOGIN ${NC}"
echo "========================================"
echo ""
echo -e "${YELLOW}PASOS MANUALES PENDIENTES:${NC}"
echo "  1. Edita los secrets con contraseñas reales:"
echo "     nano ~/secrets/db_password.txt"
echo "     nano ~/secrets/db_root_password.txt"
echo "     nano ~/secrets/credentials.txt"
echo ""
echo "  2. Cierra sesión y vuelve a entrar para"
echo "     activar el grupo docker:"
echo "     exit  →  ssh de nuevo"
echo ""
echo "  3. Añade $DOMAIN a /etc/hosts de tu HOST"
echo "     (tu máquina física, no la VM)"
echo "========================================"

echo "wp_db_p4ssw0rd" > ~/secrets/db_password.txt
echo "r00t_db_p4ssw0rd" > ~/secrets/db_root_password.txt
cat > ~/secrets/credentials.txt << EOF
ADMIN_PASS=Sup3rv1s0r_pass
WP_USER_PASS=R3ad3r_pass
EOF

# Verifica que tienen contenido
cat ~/secrets/db_password.txt
cat ~/secrets/db_root_password.txt
cat ~/secrets/credentials.txt