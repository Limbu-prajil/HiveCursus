#include "libft.h"

void print_test_result(const char *description, int result) {
    printf("%s: %s\n", description, result ? "PASS" : "FAIL");
}

void test_ft_bzero() {
    // Test variables
    char buffer0[10] = "Hello";
    char buffer[20];
    int pass;

    // Test 1: Clear the entire buffer
    ft_bzero(buffer0, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", buffer0[i]);  // Expected output: 0 0 0 0 0 0 0 0 0 0
    }
    printf("\n");

    // Test 2: Clear part of the buffer
    for (int i = 0; i < 10; i++) buffer0[i] = 'A'; // Fill buffer with 'A'
    ft_bzero(buffer0, 5);
    for (int i = 0; i < 10; i++) {
        printf("%d ", buffer0[i]);  // Expected output: 0 0 0 0 0 65 65 65 65 65 (65 is ASCII for 'A')
    }
    printf("\n");

    // Edge case: Clear zero bytes
    bzero(buffer0, 0);
    for (int i = 0; i < 10; i++) {
        printf("%d ", buffer0[i]);  // Expected output: 0 0 0 0 0 65 65 65 65 65
    }
    printf("\n");

    // Basic Case (Non-zero Memory)
    memset(buffer, 'A', sizeof(buffer));
    ft_bzero(buffer, 5);
    pass = (memcmp(buffer, "\0\0\0\0\0", 5) == 0);
    print_test_result("Basic case (first 5 bytes zeroed)", pass);

    // Full Memory Block Zeroing
    memset(buffer, 'A', sizeof(buffer));
    ft_bzero(buffer, sizeof(buffer));
    pass = (memcmp(buffer, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", sizeof(buffer)) == 0);
    print_test_result("Full memory block zeroing", pass);

    // Zero-Length Input
    memset(buffer, 'A', sizeof(buffer));
    ft_bzero(buffer, 0);
    pass = (memcmp(buffer, "AAAAAAAAAAAAAAAAAAAA", sizeof(buffer)) == 0);
    print_test_result("Zero-length input (memory unchanged)", pass);

    // Boundary Condition (One Byte)
    memset(buffer, 'A', sizeof(buffer));
    ft_bzero(buffer, 1);
    pass = (buffer[0] == '\0' && buffer[1] == 'A');
    print_test_result("Boundary condition (one byte zeroed)", pass);

    // Partial Memory Zeroing
    memset(buffer, 'A', sizeof(buffer));
    ft_bzero(buffer, 10);
    pass = (memcmp(buffer, "\0\0\0\0\0\0\0\0\0\0", 10) == 0 && buffer[10] == 'A');
    print_test_result("Partial memory zeroing (first 10 bytes zeroed)", pass);

    // Large Buffer Test
    char *large_buffer = malloc(100000);
    memset(large_buffer, 'A', 100000);
    ft_bzero(large_buffer, 100000);
    pass = (memcmp(large_buffer, "\0\0\0\0\0", 5) == 0); // Spot-checking
    print_test_result("Large buffer test (first 5 bytes zeroed)", pass);
    free(large_buffer);

    // Memory Alignment Consideration
    char misaligned_buffer[21];
    memset(misaligned_buffer, 'A', sizeof(misaligned_buffer));
    ft_bzero(misaligned_buffer + 1, 10);
    pass = (misaligned_buffer[0] == 'A' && memcmp(misaligned_buffer + 1, "\0\0\0\0\0\0\0\0\0\0", 10) == 0);
    print_test_result("Memory alignment consideration", pass);
}

int main() {
    test_ft_bzero();
    return 0;
}
