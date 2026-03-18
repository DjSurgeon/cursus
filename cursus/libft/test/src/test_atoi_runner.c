#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[0;32m"
#define RED   "\033[0;31m"
#define NC    "\033[0m"
#define BOLD  "\033[1m"

void test_atoi(const char *str) {
    int expected = atoi(str);
    int actual = ft_atoi(str);
    if (expected == actual) {
        printf("  " GREEN "✅ PASS:" NC " Input \"%s\" -> %d\n", str, actual);
    } else {
        printf("  " RED "❌ FAIL:" NC " Input \"%s\" -> Expected: %d, Actual: %d\n", str, expected, actual);
        exit(1);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    test_atoi(argv[1]);
    return 0;
}
