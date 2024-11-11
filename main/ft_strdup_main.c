#include "libft.h"

void print_test_result(const char *description, int result) {
    printf("%s: %s\n", description, result ? "PASS" : "FAIL");
}

void test_ft_strdup() {
    char *result;

    // Standard string duplication
    const char *str1 = "Hello, World!";
    result = ft_strdup(str1);
    int standard_duplication_pass = result && strcmp(result, str1) == 0;
    print_test_result("Standard string duplication", standard_duplication_pass);
    free(result);

    // Empty string
    const char *empty_str = "";
    result = ft_strdup(empty_str);
    int empty_string_pass = result && strcmp(result, empty_str) == 0;
    print_test_result("Empty string duplication", empty_string_pass);
    free(result);

    // String with special characters
    const char *special_str = "Hello\nWorld\t!";
    result = ft_strdup(special_str);
    int special_chars_pass = result && strcmp(result, special_str) == 0;
    print_test_result("String with special characters", special_chars_pass);
    free(result);

    // String with embedded null characters
    const char embedded_null_str[] = "hello\0world";
    result = ft_strdup(embedded_null_str);
    int embedded_null_pass = result && strcmp(result, "hello") == 0;
    print_test_result("String with embedded null character", embedded_null_pass);
    free(result);

    // Very large string duplication
    const size_t large_size = 1000000;  // 1 million characters
    char *large_str = malloc(large_size + 1);
    if (large_str) {
        memset(large_str, 'A', large_size);
        large_str[large_size] = '\0';  // Null-terminate the large string
        result = ft_strdup(large_str);
        int large_string_pass = result && strcmp(result, large_str) == 0;
        print_test_result("Very large string duplication", large_string_pass);
        free(result);
        free(large_str);
    } else {
        printf("Skipping very large string test due to memory allocation failure\n");
    }
}

int main() {
    printf("Testing ft_strdup...\n");
    test_ft_strdup();
    return 0;
}

