#include "../libft/libft.h"

void print_test_result(const char *description, int result) {
    printf("%s: %s\n", description, result ? "PASS" : "FAIL");
}

void test_ft_memcmp() {
    char buffer1[] = "abcdef";
    char buffer2[] = "abcdef";
    char buffer3[] = "abcdeg";
    char buffer4[] = "abc";
    char buffer5[] = "abcdef\0xyz";

    // Identical blocks
    print_test_result("Identical blocks (abcdef vs abcdef)", ft_memcmp(buffer1, buffer2, 6) == 0);

    // Different blocks (difference at last character)
    print_test_result("Different blocks (abcdef vs abcdeg)", ft_memcmp(buffer1, buffer3, 6) < 0);

    // Prefix match but different length
    print_test_result("Prefix match, different lengths (abc vs abcdef)", ft_memcmp(buffer4, buffer1, 3) == 0);

    // Buffer with null bytes - compare up to null byte (should be equal)
    print_test_result("Comparison with null bytes, up to null byte (abcdef vs abcdef\\0xyz)", ft_memcmp(buffer1, buffer5, 6) == 0);

    // Buffer with null bytes - compare including null byte (should detect difference)
    print_test_result("Comparison with null bytes (abcdef vs abcdef\\0xyz)", ft_memcmp(buffer1, buffer5, 10) != 0);

    // Zero-length comparison
    print_test_result("Zero-length comparison (abcdef vs abcdef, length 0)", ft_memcmp(buffer1, buffer2, 0) == 0);

    // Boundary condition: Difference at start
    print_test_result("Difference at start (x vs a)", ft_memcmp("x", "a", 1) > 0);

    // Boundary condition: Difference at end
    print_test_result("Difference at end (abcdez vs abcdef)", ft_memcmp("abcdez", "abcdef", 6) > 0);

    // Non-printable characters
    char non_print1[] = {0, 1, 2, 3, 4};
    char non_print2[] = {0, 1, 2, 3, 5};
    print_test_result("Non-printable characters (difference at end)", ft_memcmp(non_print1, non_print2, 5) < 0);
}

int main() {
    printf("Testing ft_memcmp...\n");
    test_ft_memcmp();
    return 0;
}

