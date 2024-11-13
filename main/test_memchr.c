#include "../libft/libft.h"

void print_test_result(const char *description, int result) {
    printf("%s: %s\n", description, result ? "PASS" : "FAIL");
}

void test_ft_memchr() {
    char buffer[] = "Hello, World!";
    
    // Single occurrence
    print_test_result("Single occurrence (find 'W')", ft_memchr(buffer, 'W', strlen(buffer)) == &buffer[7]);

    // Multiple occurrences
    print_test_result("Multiple occurrences (find 'o')", ft_memchr(buffer, 'o', strlen(buffer)) == &buffer[4]);

    // Character not found
    print_test_result("Character not found (find 'x')", ft_memchr(buffer, 'x', strlen(buffer)) == NULL);

    // Zero-length search
    print_test_result("Zero-length search (find 'H' with length 0)", ft_memchr(buffer, 'H', 0) == NULL);
    
    // Edge boundary: First byte in the memory block
    print_test_result("Edge boundary (find first byte 'H')", ft_memchr(buffer, 'H', strlen(buffer)) == &buffer[0]);

    // Edge boundary: Last byte in the memory block
    print_test_result("Edge boundary (find last byte '!')", ft_memchr(buffer, '!', strlen(buffer)) == &buffer[strlen(buffer) - 1]);
}

int main() {
    printf("Testing ft_memchr...\n");
    test_ft_memchr();
    return 0;
}

