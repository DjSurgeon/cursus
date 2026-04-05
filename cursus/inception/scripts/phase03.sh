#!/bin/bash
# =============================================================================
# Inception — Environment Variables Generator (.env)
# Uso: bash phase03.sh <tu_login_de_42>
# =============================================================================

# Colores
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m'

# Validación de argumentos
LOGIN=$1
if [ -z "$LOGIN" ]; then
    echo -e "${RED}Error: Debes pasar tu login como argumento.${NC}"
    echo "Uso: bash phase03.sh <login>"
    exit 1
fi

# Ruta del archivo (asumiendo ejecución desde la raíz o scripts/)
PROJECT_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
ENV_FILE="$PROJECT_ROOT/intra/srcs/.env"

echo -e "${BLUE}Generando archivo .env en $ENV_FILE...${NC}"

# Crear el archivo .env con los valores requeridos
cat > "$ENV_FILE" << EOF
# Domain
DOMAIN_NAME=${LOGIN}.42.fr

# MariaDB (Configuración de base de datos)
MYSQL_DATABASE=wordpress
MYSQL_USER=wpuser

# WordPress Users (Configuración inicial)
# Nota: El administrador NO puede contener "admin" o "administrator" (Regla 42)
WP_ADMIN_USER=supervisor
WP_ADMIN_EMAIL=supervisor@${LOGIN}.42.fr

# Segundo usuario (Requisito del subject)
WP_USER=reader
WP_USER_EMAIL=reader@${LOGIN}.42.fr
EOF

echo -e "${GREEN}¡Archivo .env generado con éxito para el login: $LOGIN!${NC}"
echo "----------------------------------------------------"
cat "$ENV_FILE"
echo "----------------------------------------------------"
