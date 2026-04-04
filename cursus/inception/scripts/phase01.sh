#!/bin/bash
# =============================================================================
# Inception — Environment Setup Script (Ubuntu 24.04)
# Uso: bash phase01.sh <tu_login_de_42>
# =============================================================================

# Salir inmediatamente si ocurre un error
set -e

# ── Colores para output ───────────────────────────────────────────────────────
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

ok()    { echo -e "${GREEN}[OK]${NC} $1"; }
warn()  { echo -e "${YELLOW}[WARN]${NC} $1"; }
fail()  { echo -e "${RED}[FAIL]${NC} $1"; }
info()  { echo -e "${BLUE}[INFO]${NC} $1"; }

# ── Validación de argumentos ──────────────────────────────────────────────────
LOGIN=$1
if [ -z "$LOGIN" ]; then
    fail "Debes pasar tu login de 42 como argumento"
    echo "Uso: bash phase01.sh <login>"
    exit 1
fi

echo "===================================================="
echo "  Inception Environment Setup — Login: $LOGIN"
echo "===================================================="

# ── 1. Actualización del Sistema y Herramientas ──────────────────────────────
info "Actualizando el sistema e instalando herramientas base..."
sudo apt-get update -y
sudo apt-get install -y \
    curl wget git make ca-certificates gnupg lsb-release \
    build-essential
ok "Sistema actualizado y herramientas instaladas."

# ── 2. Instalación de Docker (Repositorio Oficial) ───────────────────────────
info "Instalando Docker Engine y Docker Compose Plugin..."

# Configurar la llave GPG de Docker
sudo install -m 0755 -d /etc/apt/keyrings
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg --yes
sudo chmod a+r /etc/apt/keyrings/docker.gpg

# Añadir el repositorio a las fuentes de Apt
echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
  $(. /etc/os-release && echo "$VERSION_CODENAME") stable" | \
  sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

sudo apt-get update -y
sudo apt-get install -y docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin

# Gestionar permisos del usuario actual
if ! getent group docker > /dev/null; then
    sudo groupadd docker
fi
sudo usermod -aG docker "$USER"
ok "Docker instalado. Usuario añadido al grupo 'docker'."

# ── 3. Configuración de Infraestructura (Hosts y Volúmenes) ──────────────────
info "Configurando dominio y directorios de volúmenes..."

# Mapeo del dominio local
DOMAIN="${LOGIN}.42.fr"
if grep -q "$DOMAIN" /etc/hosts; then
    warn "El dominio $DOMAIN ya existe en /etc/hosts."
else
    echo "127.0.0.1  $DOMAIN" | sudo tee -a /etc/hosts > /dev/null
    ok "Dominio $DOMAIN añadido a /etc/hosts."
fi

# Directorios de datos (Requisito del Subject)
DATA_PATH="/home/${LOGIN}/data"
info "Creando directorios de volúmenes en $DATA_PATH..."
sudo mkdir -p "$DATA_PATH/mariadb"
sudo mkdir -p "$DATA_PATH/wordpress"
# Asegurar permisos si el usuario coincide con el login o si estamos en la VM
sudo chown -R "$USER":"$USER" "/home/${LOGIN}" 2>/dev/null || true
ok "Volúmenes de datos preparados."

# Directorio de Secretos (Para Docker Secrets)
mkdir -p "$HOME/secrets"
ok "Directorio de secretos creado en $HOME/secrets"

# ── 4. Inicialización de Configuración (.env y Secretos) ──────────────────────
info "Inicializando archivos de configuración..."

# Detectar la raíz del proyecto (asumiendo que se ejecuta desde scripts/ o la raíz)
PROJECT_ROOT="$(cd "$(dirname "$0")/.." && pwd)"

# Generar .env desde el ejemplo si existe la carpeta intra/srcs
if [ -d "$PROJECT_ROOT/intra/srcs" ]; then
    ENV_FILE="$PROJECT_ROOT/intra/srcs/.env"
    ENV_EXAMPLE="$PROJECT_ROOT/intra/srcs/.env.example"

    if [ -f "$ENV_EXAMPLE" ] && [ ! -f "$ENV_FILE" ]; then
        sed "s/serjimen/$LOGIN/g" "$ENV_EXAMPLE" > "$ENV_FILE"
        ok ".env generado en intra/srcs/ (revisar valores manualmente)."
    else
        warn ".env ya existe o no se encontró .env.example."
    fi
fi

# Generar secretos de marcador de posición (PLACEHOLDERS)
if [ ! -f "$HOME/secrets/db_password.txt" ]; then
    echo "wp_db_p4ssw0rd" > "$HOME/secrets/db_password.txt"
    echo "r00t_db_p4ssw0rd" > "$HOME/secrets/db_root_password.txt"
    cat > "$HOME/secrets/credentials.txt" << EOF
ADMIN_PASS=Sup3rv1s0r_pass
WP_USER_PASS=R3ad3r_pass
EOF
    ok "Secretos temporales creados en $HOME/secrets/ (¡CÁMBIALOS!)"
fi

# ── 5. Verificación Final ─────────────────────────────────────────────────────
echo ""
info "Resumen de instalación:"
docker --version
docker compose version
echo -e "Dominio: $(grep "$DOMAIN" /etc/hosts)"
echo -e "Volúmenes: $DATA_PATH"

echo ""
echo "===================================================="
echo -e "${GREEN}  ¡Configuración completada para $LOGIN!  ${NC}"
echo "===================================================="
echo -e "${YELLOW}PRÓXIMOS PASOS:${NC}"
echo "  1. Reinicia tu sesión: 'newgrp docker' o cierra/abre sesión."
echo "  2. Edita los secretos en ~/secrets/ con tus contraseñas reales."
echo "  3. Despliegue: 'cd intra && make up-alpine'"
echo "===================================================="