#!/bin/bash

# Load utility functions
source ./utils.sh

echo -e "${BOLD}${BLUE}==================================================${NC}"
echo -e "${BOLD}${BLUE}          STARTING LIBFT TEST SUITE               ${NC}"
echo -e "${BOLD}${BLUE}==================================================${NC}\n"

# Make sure the library is compiled
# Using -j$(nproc) for faster parallel compilation
cd ../.. && make -j$(nproc) > /dev/null && cd test/scripts

if [ $? -ne 0 ]; then
    print_error "Makefile failed to compile libft.a"
    exit 1
fi

chmod +x test_ft_atoi.sh
chmod +x test_ft_bzero.sh
chmod +x test_ft_calloc.sh
chmod +x test_ft_countchar.sh
chmod +x test_ft_isalnum.sh
chmod +x test_ft_isalpha.sh
chmod +x test_ft_isascii.sh
chmod +x test_ft_isdigit.sh
chmod +x test_ft_isprint.sh
chmod +x test_ft_isspace.sh
chmod +x test_ft_itoa.sh
chmod +x test_ft_lstadd_back.sh
chmod +x test_ft_lstadd_front.sh
chmod +x test_ft_lstclear.sh
chmod +x test_ft_lstdelone.sh
chmod +x test_ft_lstiter.sh
chmod +x test_ft_memchr.sh
chmod +x test_ft_memcmp.sh
chmod +x test_ft_memcpy.sh
chmod +x test_ft_strjoin.sh

./test_ft_atoi.sh
FT_ATOI_RES=$?

./test_ft_bzero.sh
FT_BZERO_RES=$?

./test_ft_calloc.sh
FT_CALLOC_RES=$?

./test_ft_countchar.sh
FT_COUNTCHAR_RES=$?

./test_ft_isalnum.sh
FT_ISALNUM_RES=$?

./test_ft_isalpha.sh
FT_ISALPHA_RES=$?

./test_ft_isascii.sh
FT_ISASCII_RES=$?

./test_ft_isdigit.sh
FT_ISDIGIT_RES=$?

./test_ft_isprint.sh
FT_ISPRINT_RES=$?

./test_ft_isspace.sh
FT_ISSPACE_RES=$?

./test_ft_itoa.sh
FT_ITOA_RES=$?

./test_ft_lstadd_back.sh
FT_LSTADD_BACK_RES=$?

./test_ft_lstadd_front.sh
FT_LSTADD_FRONT_RES=$?

./test_ft_lstclear.sh
FT_LSTCLEAR_RES=$?

./test_ft_lstdelone.sh
FT_LSTDELONE_RES=$?

./test_ft_lstiter.sh
FT_LSTITER_RES=$?

./test_ft_memchr.sh
FT_MEMCHR_RES=$?

./test_ft_memcmp.sh
FT_MEMCMP_RES=$?

./test_ft_memcpy.sh
FT_MEMCPY_RES=$?

./test_ft_strjoin.sh
FT_STRJOIN_RES=$?

echo -e "\n${BOLD}${CYAN}==================================================${NC}"
echo -e "${BOLD}${CYAN}                GLOBAL RESULTS                    ${NC}"
echo -e "${BOLD}${CYAN}==================================================${NC}"

TOTAL_FAILED=$((FT_ATOI_RES + FT_BZERO_RES + FT_CALLOC_RES + FT_COUNTCHAR_RES + FT_ISALNUM_RES + FT_ISALPHA_RES + FT_ISASCII_RES + FT_ISDIGIT_RES + FT_ISPRINT_RES + FT_ISSPACE_RES + FT_ITOA_RES + FT_LSTADD_BACK_RES + FT_LSTADD_FRONT_RES + FT_LSTCLEAR_RES + FT_LSTDELONE_RES + FT_LSTITER_RES + FT_MEMCHR_RES + FT_MEMCMP_RES + FT_MEMCPY_RES + FT_STRJOIN_RES))

if [ $TOTAL_FAILED -eq 0 ]; then
    echo -e "${BOLD}${GREEN}  ${ICON_STAR}  CONGRATULATIONS! ALL TESTS PASSED!  ${ICON_STAR}  ${NC}"
else
    echo -e "${BOLD}${RED}  ${ICON_FAIL}  SOME FUNCTIONS FAILED THE TESTS.    ${NC}"
fi
echo -e "${BOLD}${CYAN}==================================================${NC}\n"

exit $TOTAL_FAILED
