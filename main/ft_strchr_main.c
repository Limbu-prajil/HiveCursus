#include "libft.h"

void print_test_result(const char *description, int result) {
    printf("%s: %s\n", description, result ? "PASS" : "FAIL");
}

void test_ft_strchr() {
    const char *str1 = "Hello, World!";
    const char *str2 = "abcabcabc";
    const char *empty_str = "";

    // Character found in the middle of the string
    char *result = ft_strchr(str1, 'o');
    print_test_result("Character found in the middle (o)", result == str1 + 4);

    // Character found at the beginning of the string
    result = ft_strchr(str1, 'H');
    print_test_result("Character found at the beginning (H)", result == str1);

    // Character found at the end of the string
    result = ft_strchr(str1, '!');
    print_test_result("Character found at the end (!)", result == str1 + strlen(str1) - 1);

    // Character not found in the string
    result = ft_strchr(str1, 'z');
    print_test_result("Character not found (z)", result == NULL);

    // Null character search
    result = ft_strchr(str1, '\0');
    print_test_result("Null character search (\\0)", result == str1 + strlen(str1));

    // Empty string with any character search
    result = ft_strchr(empty_str, 'a');
    print_test_result("Empty string, search for any character", result == NULL);

    // Empty string, search for null character
    result = ft_strchr(empty_str, '\0');
    print_test_result("Empty string, search for null character (\\0)", result == empty_str);

    // String with repeated characters, should find first occurrence
    result = ft_strchr(str2, 'a');
    print_test_result("Repeated characters, find first occurrence of 'a'", result == str2);

    // Edge case: searching for the first character in a single character string
    const char *single_char_str = "x";
    result = ft_strchr(single_char_str, 'x');
    print_test_result("Single character string, find existing character 'x'", result == single_char_str);

    // Edge case: searching for a character not in a single character string
    result = ft_strchr(single_char_str, 'y');
    print_test_result("Single character string, search for non-existing character 'y'", result == NULL);
}

int main() {
    printf("Testing ft_strchr...\n");
    test_ft_strchr();
    return 0;
}

