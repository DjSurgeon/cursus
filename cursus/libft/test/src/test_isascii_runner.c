#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "libft.h"

#define GREEN "\033[0;32m"
#define RED   "\033[0;31m"
#define NC    "\033[0m"

void test_isascii(int c) {
    int expected = isascii(c);
    int actual = ft_isascii(c);
    if ((expected != 0) == (actual != 0)) {
        printf("  " GREEN "✅ PASS:" NC " Input %d -> %d\n", c, actual);
    } else {
        printf("  " RED "❌ FAIL:" NC " Input %d -> Expected: %d, Actual: %d\n", c, expected, actual);
        exit(1);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    test_isascii(atoi(argv[1]));
    return 0;
}
