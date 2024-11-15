#include "../libft/libft.h"

void print_test_result(const char *description, int result) {
    printf("%s: %s\n", description, result ? "PASS" : "FAIL");
}

void test_ft_isdigit() {
    int pass;

    // Numeric Characters (0-9)
    pass = 1;
    for (char c = '0'; c <= '9'; c++) {
        if (ft_isdigit(c) != 1) pass = 0;
    }
    print_test_result("Numeric characters (0-9)", pass);

    // Non-Numeric Characters
    const char non_digit_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()-=_+[]{}|;:'\",.<>/?\\~` \n\t";
    pass = 1;
    for (int i = 0; non_digit_chars[i] != '\0'; i++) {
        if (ft_isdigit(non_digit_chars[i]) != 0) pass = 0;
    }
    print_test_result("Non-numeric characters", pass);

    // Boundary Characters
    print_test_result("Boundary character '/'", ft_isdigit('/') == 0);
    print_test_result("Boundary character ':'", ft_isdigit(':') == 0);

    // Extended ASCII Characters
    pass = 1;
    for (unsigned char c = 128; c <= 255; c++) {
        if (ft_isdigit(c) != 0) pass = 0;
    }
    print_test_result("Extended ASCII characters (128-255)", pass);

    // Null Character
    print_test_result("Null character", ft_isdigit('\0') == 0);
}

int main() {
    test_ft_isdigit();
    return 0;
}

