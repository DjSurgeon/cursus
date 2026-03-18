#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

#define GREEN "\033[0;32m"
#define RED   "\033[0;31m"
#define NC    "\033[0m"

int test_countchar(char c) {
    int res;

    // ft_countchar writes to stdout, so we just check the return value here
    res = ft_countchar(c);
    if (res == 1) {
        printf("  " GREEN "✅ PASS:" NC " Char '%c' -> Returned %d\n", c, res);
        return 0;
    } else {
        printf("  " RED "❌ FAIL:" NC " Char '%c' -> Expected 1, Actual %d\n", c, res);
        return 1;
    }
}

int main(void) {
    int failed = 0;

    failed |= test_countchar('a');
    failed |= test_countchar('4');
    failed |= test_countchar('\n');
    failed |= test_countchar(' ');

    return (failed ? 1 : 0);
}
