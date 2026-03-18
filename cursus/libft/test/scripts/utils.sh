#!/bin/bash

# Colors
BOLD='\033[1m'
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Icons
ICON_PASS="✅"
ICON_FAIL="❌"
ICON_INFO="ℹ️"
ICON_WORK="⚙️"
ICON_STAR="🌟"

print_header() {
    local title=$1
    echo -e "${BOLD}${MAGENTA}==================================================${NC}"
    echo -e "${BOLD}${CYAN}  ${ICON_WORK}  TESTING: ${title}${NC}"
    echo -e "${BOLD}${MAGENTA}==================================================${NC}"
}

print_status() {
    local status=$1
    local msg=$2
    if [ "$status" -eq 0 ]; then
        echo -e "  ${GREEN}${ICON_PASS} PASS:${NC} ${msg}"
    else
        echo -e "  ${RED}${ICON_FAIL} FAIL:${NC} ${msg}"
    fi
}

print_summary() {
    local name=$1
    local failed=$2
    echo -e "\n${BOLD}${MAGENTA}--------------------------------------------------${NC}"
    if [ "$failed" -eq 0 ]; then
        echo -e "${BOLD}${GREEN}  ${ICON_STAR} ALL TESTS PASSED FOR ${name} ${ICON_STAR}${NC}"
    else
        echo -e "${BOLD}${RED}  ${ICON_FAIL} SOME TESTS FAILED FOR ${name} ${NC}"
    fi
    echo -e "${BOLD}${MAGENTA}--------------------------------------------------${NC}\n"
}

print_error() {
    echo -e "${RED}${BOLD}${ICON_FAIL} ERROR: $1${NC}"
}

print_info() {
    echo -e "${BLUE}${ICON_INFO} $1${NC}"
}

run_with_valgrind() {
    local executable=$1
    shift
    # Usamos --error-exitcode=42 para distinguir errores de valgrind de errores del programa
    valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --error-exitcode=42 --quiet ./"$executable" "$@"
    return $?
}
