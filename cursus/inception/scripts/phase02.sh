#!/bin/bash
# =============================================================================
# Inception — Secrets Generator Script
# Este script genera las credenciales necesarias para MariaDB y WordPress.
# =============================================================================

# Colores
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m'

# Directorio de destino (debe coincidir con el definido en docker-compose.yml)
SECRETS_DIR="$HOME/secrets"

echo -e "${BLUE}Generando secretos en $SECRETS_DIR...${NC}"

# Crear el directorio si no existe
mkdir -p "$SECRETS_DIR"

# 1. Contraseña del usuario de la base de datos (WordPress)
echo "wp_db_p4ssw0rd" > "$SECRETS_DIR/db_password.txt"

# 2. Contraseña del Root de MariaDB
echo "r00t_db_p4ssw0rd" > "$SECRETS_DIR/db_root_password.txt"

# 3. Credenciales de WordPress (Admin y Usuario normal)
# Formato: KEY=VALUE para que el script wp-setup.sh pueda hacer grep
cat > "$SECRETS_DIR/credentials.txt" << EOF
ADMIN_PASS=Sup3rv1s0r_pass
WP_USER_PASS=R3ad3r_pass
EOF

# Ajustar permisos (solo lectura para el usuario actual)
chmod 600 "$SECRETS_DIR/"*.txt

echo -e "${GREEN}¡Secretos generados con éxito!${NC}"
echo "----------------------------------------------------"
ls -la "$SECRETS_DIR"
echo "----------------------------------------------------"
echo -e "${BLUE}Nota: Recuerda que puedes editar estos archivos manualmente si lo prefieres.${NC}"
