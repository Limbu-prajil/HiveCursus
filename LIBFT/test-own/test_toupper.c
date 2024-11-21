#include "../libft/libft.h"

void print_test_result(const char *description, int result) {
    printf("%s: %s\n", description, result ? "PASS" : "FAIL");
}

void test_ft_toupper() {
    int pass;

    // Lowercase Alphabetic Characters (a-z)
    pass = 1;
    for (char c = 'a'; c <= 'z'; c++) {
        if (ft_toupper(c) != c - 32) pass = 0;  // ASCII difference between lower and upper is 32
    }
    print_test_result("Lowercase alphabetic characters (a-z)", pass);

    // Uppercase Alphabetic Characters (A-Z)
    pass = 1;
    for (char c = 'A'; c <= 'Z'; c++) {
        if (ft_toupper(c) != c) pass = 0;
    }
    print_test_result("Uppercase alphabetic characters (A-Z)", pass);

    // Non-Alphabetic Characters (digits, symbols, whitespace, control characters)
    const char non_alpha_chars[] = "0123456789!@#$%^&*()-=_+[]{}|;:'\",.<>/?\\~` \n\t";
    pass = 1;
    for (int i = 0; non_alpha_chars[i] != '\0'; i++) {
        if (ft_toupper(non_alpha_chars[i]) != non_alpha_chars[i]) pass = 0;
    }
    print_test_result("Non-alphabetic characters", pass);

    // Boundary Characters Around Alphabetic Ranges
    print_test_result("Boundary character '`'", ft_toupper('`') == '`');
    print_test_result("Boundary character '{'", ft_toupper('{') == '{');

    // Extended ASCII Characters (128-255)
    pass = 1;
    for (unsigned char c = 128; c <= 255; c++) {
        if (ft_toupper(c) != c) pass = 0;
    }
    print_test_result("Extended ASCII characters (128-255)", pass);

    // Null Character
    print_test_result("Null character", ft_toupper('\0') == '\0');
}

int main() {
    test_ft_toupper();
    return 0;
}

