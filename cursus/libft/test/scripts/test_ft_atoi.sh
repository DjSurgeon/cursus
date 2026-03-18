#!/bin/bash

# Load utility functions
source ./utils.sh

print_header "ft_atoi (Static Analysis + Logic)"

# Ensure libft.a and libft.h exist
if [ ! -f "../../libft.a" ] || [ ! -f "../../libft.h" ]; then
    print_error "libft.a or libft.h not found in root directory"
    exit 1
fi

# 1. Deep Static Analysis
echo -e "${BLUE}${ICON_WORK} Running GCC Static Analyzer...${NC}"
cc -Wall -Wextra -Werror -fanalyzer -c ../../ft_atoi.c -o ft_atoi.o

if [ $? -ne 0 ]; then
    print_error "Static Analysis found potential issues in ft_atoi.c"
    exit 1
else
    echo -e "${GREEN}${ICON_PASS} Static Analysis passed successfully!${NC}"
fi

# 2. Compile for Logic Test
cc -Wall -Wextra -Werror ../src/test_atoi_runner.c -L../.. -lft -I../.. -o test_atoi

if [ $? -ne 0 ]; then
    print_error "Compilation failed"
    exit 1
fi

# 3. List of test cases
TEST_CASES=(
    "0" "42" "-42" "  +42" "  -42" "2147483647" "-2147483648"
    "  "$'\t\n\r\v\f'" 42" "000042" "++42" "--42" "+-42"
    "  + 42" "42abc" "abc42" "" " " "2147483648" "-2147483649"
)

FAILED=0
for test in "${TEST_CASES[@]}"; do
    ./test_atoi "$test"
    if [ $? -ne 0 ]; then
        FAILED=1
    fi
done

# Cleanup
rm -f test_atoi ft_atoi.o

print_summary "ft_atoi" $FAILED
exit $FAILED
