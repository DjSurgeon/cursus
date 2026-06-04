#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
RESET='\033[0m'

echo -e "${BLUE}--- Starting ex00 Tests ---${RESET}"

run_test() {
    echo -e "${GREEN}Testing: ./convert \"$1\"${RESET}"
    ./convert "$1"
    echo ""
}

# Subject Examples
echo -e "${BLUE}--- Subject Examples ---${RESET}"
run_test "0"
run_test "nan"
run_test "42.0f"

# Base Types
echo -e "${BLUE}--- Base Types ---${RESET}"
run_test "a"
run_test "-42"
run_test "4.2"
run_test "-4.2f"

# Pseudo Literals
echo -e "${BLUE}--- Pseudo Literals ---${RESET}"
run_test "+inf"
run_test "-inf"
run_test "+inff"
run_test "-inff"
run_test "nanf"

# Edge Cases & Invalid Inputs
echo -e "${BLUE}--- Edge Cases & Invalid Inputs ---${RESET}"
run_test "2147483647"
run_test "2147483648"
run_test "-2147483648"
run_test "-2147483649"
run_test "invalid"
run_test "42.42.42"
run_test ""

echo -e "${BLUE}--- Tests Completed ---${RESET}"
