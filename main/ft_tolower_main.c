#include "libft.h"

void print_test_result(const char *description, int result) {
    printf("%s: %s\n", description, result ? "PASS" : "FAIL");
}

void test_ft_tolower() {
    int pass;

    // Uppercase Alphabetic Characters (A-Z)
    pass = 1;
    for (char c = 'A'; c <= 'Z'; c++) {
        if (ft_tolower(c) != c + 32) pass = 0;  // ASCII difference between upper and lower is 32
    }
    print_test_result("Uppercase alphabetic characters (A-Z)", pass);

    // Lowercase Alphabetic Characters (a-z)
    pass = 1;
    for (char c = 'a'; c <= 'z'; c++) {
        if (ft_tolower(c) != c) pass = 0;
    }
    print_test_result("Lowercase alphabetic characters (a-z)", pass);

    // Non-Alphabetic Characters (digits, symbols, whitespace, control characters)
    const char non_alpha_chars[] = "0123456789!@#$%^&*()-=_+[]{}|;:'\",.<>/?\\~` \n\t";
    pass = 1;
    for (int i = 0; non_alpha_chars[i] != '\0'; i++) {
        if (ft_tolower(non_alpha_chars[i]) != non_alpha_chars[i]) pass = 0;
    }
    print_test_result("Non-alphabetic characters", pass);

    // Boundary Characters Around Alphabetic Ranges
    print_test_result("Boundary character '@'", ft_tolower('@') == '@');
    print_test_result("Boundary character '['", ft_tolower('[') == '[');

    // Extended ASCII Characters (128-255)
    pass = 1;
    for (unsigned char c = 128; c <= 255; c++) {
        if (ft_tolower(c) != c) pass = 0;
    }
    print_test_result("Extended ASCII characters (128-255)", pass);

    // Null Character
    print_test_result("Null character", ft_tolower('\0') == '\0');
}

int main() {
    test_ft_tolower();
    return 0;
}

