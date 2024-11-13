#include "../libft/libft.h"

void print_test_result(const char *description, int result) {
    printf("%s: %s\n", description, result ? "PASS" : "FAIL");
}

void test_ft_memset() {
    char buffer[20] = "Test memset";
    char buffer1[20];
    char buffer2[20] = "InitialBufferData";

    // Standard fill
    ft_memset(buffer, '*', 5);
    print_test_result("Standard fill", strncmp(buffer, "*****memset", 10) == 0);

    // Zero-length fill
    strcpy(buffer, "Test memset");
    ft_memset(buffer, '*', 0);
    print_test_result("Zero-length fill", strcmp(buffer, "Test memset") == 0);
    
    printf("\n");
    
    // Standard fill
    ft_memset(buffer1, 'A', sizeof(buffer1));
    int standard_fill_pass = 1;
    for (int i = 0; i < buffer1[i]; i++) {
        if (buffer1[i] != 'A') {
            standard_fill_pass = 0;
            break;
        }
    }
    print_test_result("Standard fill", standard_fill_pass);

    // Zero-length set (should not change buffer)
    ft_memset(buffer2, 'B', 0);
    print_test_result("Zero-length set", strcmp(buffer2, "InitialBufferData") == 0);

    // Full buffer set
    ft_memset(buffer2, 'C', strlen(buffer2));
    int full_buffer_set_pass = 1;
    for (int i = 0; i < buffer2[i]; i++) {
        if (buffer2[i] != 'C') {
            full_buffer_set_pass = 0;
            break;
        }
    }
    print_test_result("Full buffer set", full_buffer_set_pass);

    // Partial buffer set
    char buffer3[20] = "Partial buffer test";
    ft_memset(buffer3, 'D', 5);
    int partial_buffer_set_pass = 1;
    for (int i = 0; i < 5; i++) {
        if (buffer3[i] != 'D') {
            partial_buffer_set_pass = 0;
            break;
        }
    }
    print_test_result("Partial buffer set (first 5 bytes set to 'D')", partial_buffer_set_pass && strcmp(buffer3 + 5, "ial buffer test") == 0);

    // Non-printable characters
    char buffer4[20];
    ft_memset(buffer4, '\0', 10);
    int non_printable_pass = 1;
    for (int i = 0; i < 10; i++) {
        if (buffer4[i] != '\0') {
            non_printable_pass = 0;
            break;
        }
    }
    print_test_result("Non-printable character set (null bytes)", non_printable_pass);

    // Boundary condition
    char boundary_buffer[20];
    ft_memset(boundary_buffer, 'X', 20);
    int boundary_set_pass = 1;
    for (int i = 0; i < 20; i++) {
        if (boundary_buffer[i] != 'X') {
            boundary_set_pass = 0;
            break;
        }
    }
    print_test_result("Boundary condition - full buffer set to 'X'", boundary_set_pass);
}

int main() {
    printf("\nTesting ft_memset...\n");
    test_ft_memset();
    return 0;
}

