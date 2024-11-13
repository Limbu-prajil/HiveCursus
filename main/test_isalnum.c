#include "../libft/libft.h"

void print_test_result(const char *description, int result) {
    printf("%s: %s\n", description, result ? "PASS" : "FAIL");
}

void test_ft_isalnum() {
    int pass;

    // Alphabetic Characters (Uppercase and Lowercase)
    pass = 1;
    for (char c = 'A'; c <= 'Z'; c++) {
        if (ft_isalnum(c) != 1) pass = 0;
    }
    print_test_result("Uppercase alphabetic characters", pass);

    pass = 1;
    for (char c = 'a'; c <= 'z'; c++) {
        if (ft_isalnum(c) != 1) pass = 0;
    }
    print_test_result("Lowercase alphabetic characters", pass);

    // Numeric Characters
    pass = 1;
    for (char c = '0'; c <= '9'; c++) {
        if (ft_isalnum(c) != 1) pass = 0;
    }
    print_test_result("Numeric characters", pass);

    // Non-Alphanumeric Characters
    const char non_alnum_chars[] = "!@# $%^&*()-=_+[]{}|;:'\",.<>/?\\~` \n\t";
    pass = 1;
    for (int i = 0; non_alnum_chars[i] != '\0'; i++) {
        if (ft_isalnum(non_alnum_chars[i]) != 0) pass = 0;
    }
    print_test_result("Non-alphanumeric characters", pass);

    // Boundary Characters
    pass = 1;
    const char boundary_chars[] = "/: @[`{";
    for (int i = 0; boundary_chars[i]; i++) {
        if (ft_isalnum(boundary_chars[i]) != 0) pass = 0;
    }
    print_test_result("Boundary characters", pass);

    // Extended ASCII Characters
    pass = 1;
    for (unsigned char c = 128; c <= 255; c++) {
        if (ft_isalnum(c) != 0) pass = 0;
    }
    print_test_result("Extended ASCII characters", pass);

    // Null Character
    print_test_result("Null character", ft_isalnum('\0') == 0);
}

int main() {
    test_ft_isalnum();
    return 0;
}

