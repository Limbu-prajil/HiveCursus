#include "../libft/libft.h"

void print_test_result(const char *description, int result) {
    printf("%s: %s\n", description, result ? "PASS" : "FAIL");
}

void test_ft_isascii() {
    int pass;

    // Valid ASCII Characters (0-127)
    pass = 1;
    for (int c = 0; c <= 127; c++) {
        if (ft_isascii(c) != 1) pass = 0;
    }
    print_test_result("Valid ASCII characters (0-127)", pass);

    // Non-ASCII Characters (128-255)
    pass = 1;
    for (int c = 128; c <= 255; c++) {
        if (ft_isascii(c) != 0) pass = 0;
    }
    print_test_result("Non-ASCII characters (128-255)", pass);

    // Boundary Characters
    print_test_result("Boundary character 0", ft_isascii(0) == 1);
    print_test_result("Boundary character 127", ft_isascii(127) == 1);
    print_test_result("Boundary character 128", ft_isascii(128) == 0);
    print_test_result("Boundary character 255", ft_isascii(255) == 0);

    // Control Characters (0-31)
    pass = 1;
    for (int c = 0; c <= 31; c++) {
        if (ft_isascii(c) != 1) pass = 0;
    }
    print_test_result("Control characters (0-31)", pass);

    // Printable ASCII Characters (32-126)
    pass = 1;
    for (int c = 32; c <= 126; c++) {
        if (ft_isascii(c) != 1) pass = 0;
    }
    print_test_result("Printable ASCII characters (32-126)", pass);
}

int main() {
    test_ft_isascii();
    return 0;
}

