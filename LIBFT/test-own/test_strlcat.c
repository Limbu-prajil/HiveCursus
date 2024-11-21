#include "../libft/libft.h"

void print_test_result(const char *description, int result) {
    printf("%s: %s\n", description, result ? "PASS" : "FAIL");
}

void test_ft_strlcat() {
    char buffer[50];
    size_t result;

    // Exact buffer size for concatenation
    strcpy(buffer, "Hello, ");
    result = ft_strlcat(buffer, "World!", sizeof(buffer));
    print_test_result("Exact buffer size", strcmp(buffer, "Hello, World!") == 0 && result == strlen("Hello, World!"));

    // Buffer too small for concatenation
    strcpy(buffer, "Hello, ");
    result = ft_strlcat(buffer, "there, how are you?", 10);  // Limiting buffer size to 10
    print_test_result("Buffer too small", strcmp(buffer, "Hello, th") == 0 && result == strlen("Hello, ") + strlen("there, how are you?"));

    // dstsize is 0
    strcpy(buffer, "Hello, ");
    result = ft_strlcat(buffer, "World!", 0);
    print_test_result("dstsize is 0", strcmp(buffer, "Hello, ") == 0 && result == strlen("World!"));

    // dstsize less than length of dst
    strcpy(buffer, "Hello, World!");
    result = ft_strlcat(buffer, "Extra text", 5);  // Limiting to 5, smaller than initial "Hello, World!"
    print_test_result("dstsize less than length of dst", strcmp(buffer, "Hello, World!") == 0 && result == 5 + strlen("Extra text"));

    // dst is empty
    strcpy(buffer, "");
    result = ft_strlcat(buffer, "Hello!", sizeof(buffer));
    print_test_result("dst is empty", strcmp(buffer, "Hello!") == 0 && result == strlen("Hello!"));

    // src is empty
    strcpy(buffer, "Hello, World!");
    result = ft_strlcat(buffer, "", sizeof(buffer));
    print_test_result("src is empty", strcmp(buffer, "Hello, World!") == 0 && result == strlen("Hello, World!"));

    // Both src and dst are empty
    strcpy(buffer, "");
    result = ft_strlcat(buffer, "", sizeof(buffer));
    print_test_result("Both src and dst are empty", strcmp(buffer, "") == 0 && result == 0);
}

int main() {
    printf("Testing ft_strlcat...\n");
    test_ft_strlcat();
    return 0;
}

