#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

#define GREEN "\033[0;32m"
#define RED   "\033[0;31m"
#define NC    "\033[0m"

int test_strjoin(const char *s1, const char *s2, const char *expected) {
    char *actual = ft_strjoin(s1, s2);
    
    if (actual == NULL && expected == NULL) {
        printf("  " GREEN "✅ PASS:" NC " Input (\"%s\", \"%s\") -> NULL (as expected)\n", s1 ? s1 : "NULL", s2 ? s2 : "NULL");
        return 0;
    }

    if (actual == NULL || expected == NULL || strcmp(actual, expected) != 0) {
        printf("  " RED "❌ FAIL:" NC " Input (\"%s\", \"%s\") -> Expected: \"%s\", Actual: \"%s\"\n", 
               s1 ? s1 : "NULL", s2 ? s2 : "NULL", expected ? expected : "NULL", actual ? actual : "NULL");
        free(actual);
        return 1;
    }

    printf("  " GREEN "✅ PASS:" NC " Input (\"%s\", \"%s\") -> \"%s\"\n", s1, s2, actual);
    free(actual);
    return 0;
}

int main(void) {
    int failed = 0;

    failed |= test_strjoin("Hello ", "World", "Hello World");
    failed |= test_strjoin("", "World", "World");
    failed |= test_strjoin("Hello ", "", "Hello ");
    failed |= test_strjoin("", "", "");
    failed |= test_strjoin("42 ", "is awesome", "42 is awesome");

    return (failed ? 1 : 0);
}
