#include "libft.h"

void print_test_result(const char *description, int result) {
    printf("%s: %s\n", description, result ? "PASS" : "FAIL");
}

void test_ft_strlcpy() {
    char buffer[50];
    size_t result;

    // Standard copy with sufficient dstsize
    const char *src1 = "Hello, World!";
    memset(buffer, 0, sizeof(buffer));  // Clear buffer
    result = ft_strlcpy(buffer, src1, sizeof(buffer));
    print_test_result("Standard copy with sufficient dstsize", strcmp(buffer, src1) == 0 && result == strlen(src1));

    // Truncated copy when dstsize is smaller
    const char *src2 = "This is a long string that will be truncated.";
    memset(buffer, 0, sizeof(buffer));
    result = ft_strlcpy(buffer, src2, 10);  // Buffer size 10
    print_test_result("Truncated copy with small dstsize", strncmp(buffer, src2, 9) == 0 && buffer[9] == '\0' && result == strlen(src2));

    // dstsize is 0
    const char *src3 = "Hello!";
    memset(buffer, 'A', sizeof(buffer));  // Fill with 'A' to detect any changes
    result = ft_strlcpy(buffer, src3, 0);
    print_test_result("dstsize is 0", buffer[0] == 'A' && result == strlen(src3));

    // Empty dst buffer with non-zero dstsize
    const char *src4 = "Test string";
    memset(buffer, 0, sizeof(buffer));
    result = ft_strlcpy(buffer, src4, sizeof(buffer));
    print_test_result("Empty dst buffer with non-zero dstsize", strcmp(buffer, src4) == 0 && result == strlen(src4));

    // Empty src string
    const char *src5 = "";
    memset(buffer, 0, sizeof(buffer));
    result = ft_strlcpy(buffer, src5, sizeof(buffer));
    print_test_result("Empty src string", buffer[0] == '\0' && result == 0);

    // Both src and dst are empty
    const char *src6 = "";
    memset(buffer, 0, sizeof(buffer));
    result = ft_strlcpy(buffer, src6, 0);
    print_test_result("Both src and dst are empty", buffer[0] == '\0' && result == 0);

    // Very large src string with small dstsize
    const char *src7 = "A very long string that definitely exceeds the small buffer size provided.";
    memset(buffer, 0, sizeof(buffer));
    result = ft_strlcpy(buffer, src7, 5);  // Small buffer size of 5
    print_test_result("Very large src string with small dstsize", strncmp(buffer, src7, 4) == 0 && buffer[4] == '\0' && result == strlen(src7));
}

int main() {
    printf("Testing ft_strlcpy...\n");
    test_ft_strlcpy();
    return 0;
}

