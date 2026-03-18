#!/bin/bash

# Load utility functions
source ./utils.sh

print_header "ft_isalpha (Static Analysis + Logic)"

# Ensure libft.a and libft.h exist
if [ ! -f "../../libft.a" ] || [ ! -f "../../libft.h" ]; then
    print_error "libft.a or libft.h not found in root directory"
    exit 1
fi

# 1. Deep Static Analysis
echo -e "${BLUE}${ICON_WORK} Running GCC Static Analyzer...${NC}"
cc -Wall -Wextra -Werror -fanalyzer -c ../../ft_isalpha.c -o ft_isalpha.o

if [ $? -ne 0 ]; then
    print_error "Static Analysis found potential issues in ft_isalpha.c"
    exit 1
else
    echo -e "${GREEN}${ICON_PASS} Static Analysis passed successfully!${NC}"
fi

# 2. Compile for Logic Test
cc -Wall -Wextra -Werror ../src/test_isalpha_runner.c -L../.. -lft -I../.. -o test_isalpha

if [ $? -ne 0 ]; then
    print_error "Compilation failed"
    exit 1
fi

# 3. List of test cases (ASCII values)
TEST_CASES=(
    "65" "90" "97" "122" "48" "57" "32" "33" "126" "0" "127" "-1"
)

FAILED=0
for test in "${TEST_CASES[@]}"; do
    # Run logic test with Valgrind
    run_with_valgrind "test_isalpha" "$test"
    RES=$?
    if [ $RES -eq 42 ]; then
        print_error "Valgrind detected memory issues for input: \"$test\""
        FAILED=1
    elif [ $RES -ne 0 ]; then
        FAILED=1
    fi
done

# Cleanup
rm -f test_isalpha ft_isalpha.o

print_summary "ft_isalpha" $FAILED
exit $FAILED
