#include "libft.h"

void print_test_result(const char *description, int result) {
    printf("%s: %s\n", description, result ? "PASS" : "FAIL");
}

void test_ft_isprint() {
    int pass;

    // Printable Characters (32-126)
    pass = 1;
    for (int c = 32; c <= 126; c++) {
        if (ft_isprint(c) != 1) pass = 0;
    }
    print_test_result("Printable characters (32-126)", pass);

    // Non-Printable Characters (0-31)
    pass = 1;
    for (int c = 0; c <= 31; c++) {
        if (ft_isprint(c) != 0) pass = 0;
    }
    print_test_result("Non-printable characters (0-31)", pass);

    // Boundary Characters
    print_test_result("Boundary character 31 (non-printable)", ft_isprint(31) == 0);
    print_test_result("Boundary character 127 (non-printable)", ft_isprint(127) == 0);

    // Extended ASCII Characters (128-255)
    pass = 1;
    for (unsigned char c = 128; c <= 255; c++) {
        if (ft_isprint(c) != 0) pass = 0;
    }
    print_test_result("Extended ASCII characters (128-255)", pass);

    // Null Character
    print_test_result("Null character", ft_isprint('\0') == 0);
}

int main() {
    test_ft_isprint();
    return 0;
}

