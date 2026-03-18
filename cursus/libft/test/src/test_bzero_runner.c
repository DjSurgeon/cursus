#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "libft.h"

#define GREEN "\033[0;32m"
#define RED   "\033[0;31m"
#define NC    "\033[0m"

void print_buffer(unsigned char *buf, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%02x ", buf[i]);
    }
    printf("\n");
}

int test_bzero(size_t size, size_t n) {
    unsigned char *buf1 = malloc(size);
    unsigned char *buf2 = malloc(size);

    if (!buf1 || !buf2) return 1;

    for (size_t i = 0; i < size; i++) {
        buf1[i] = (unsigned char)(i % 255 + 1);
        buf2[i] = (unsigned char)(i % 255 + 1);
    }

    ft_bzero(buf1, n);
    bzero(buf2, n);

    if (memcmp(buf1, buf2, size) == 0) {
        printf("  " GREEN "✅ PASS:" NC " Size %zu, Zeroing %zu bytes\n", size, n);
        free(buf1);
        free(buf2);
        return 0;
    } else {
        printf("  " RED "❌ FAIL:" NC " Size %zu, Zeroing %zu bytes\n", size, n);
        printf("    Expected: "); print_buffer(buf2, size);
        printf("    Actual:   "); print_buffer(buf1, size);
        free(buf1);
        free(buf2);
        return 1;
    }
}

int main(void) {
    int failed = 0;

    failed |= test_bzero(10, 5);
    failed |= test_bzero(10, 0);
    failed |= test_bzero(10, 10);
    failed |= test_bzero(1, 1);
    failed |= test_bzero(100, 100);
    failed |= test_bzero(100, 1);

    return (failed ? 1 : 0);
}
