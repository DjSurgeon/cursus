#!/bin/bash

# Load utility functions
source ./utils.sh

print_header "ft_itoa (Static Analysis + Logic)"

# Ensure libft.a and libft.h exist
if [ ! -f "../../libft.a" ] || [ ! -f "../../libft.h" ]; then
    print_error "libft.a or libft.h not found in root directory"
    exit 1
fi

# 1. Deep Static Analysis
echo -e "${BLUE}${ICON_WORK} Running GCC Static Analyzer...${NC}"
cc -Wall -Wextra -Werror -fanalyzer -c ../../ft_itoa.c -o ft_itoa.o

if [ $? -ne 0 ]; then
    print_error "Static Analysis found potential issues in ft_itoa.c"
    exit 1
else
    echo -e "${GREEN}${ICON_PASS} Static Analysis passed successfully!${NC}"
fi

# 2. Compile for Logic Test
cc -Wall -Wextra -Werror ../src/test_itoa_runner.c -L../.. -lft -I../.. -o test_itoa

if [ $? -ne 0 ]; then
    print_error "Compilation failed"
    exit 1
fi

# 3. Run the test with Valgrind
run_with_valgrind "test_itoa"
RES=$?

if [ $RES -eq 42 ]; then
    print_error "Valgrind detected memory issues in ft_itoa"
    FAILED=1
else
    FAILED=$RES
fi

# Cleanup
rm -f test_itoa ft_itoa.o

print_summary "ft_itoa" $FAILED
exit $FAILED
