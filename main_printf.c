#include <stdio.h>
#include <limits.h>

// Declare ft_printf prototype
int ft_printf(const char *s, ...);

int main(void)
{
    int ret_ft_printf;
    int ret_printf;

    // Test with simple string
    printf("Test 1: Simple String\n");
    ret_ft_printf = ft_printf("Hello, World!\n");
    ret_printf = printf("Hello, World!\n");
    printf("ft_printf return: %d, printf return: %d\n\n", ret_ft_printf, ret_printf);

    // Test with char specifier
    printf("Test 2: Char Specifier\n");
    ret_ft_printf = ft_printf("Character: %c\n", 'A');
    ret_printf = printf("Character: %c\n", 'A');
    printf("ft_printf return: %d, printf return: %d\n\n", ret_ft_printf, ret_printf);

    // Test with string specifier
    printf("Test 3: String Specifier\n");
    ret_ft_printf = ft_printf("String: %s\n", "Hello ft_printf!");
    ret_printf = printf("String: %s\n", "Hello ft_printf!");
    printf("ft_printf return: %d, printf return: %d\n\n", ret_ft_printf, ret_printf);

    // Test with integer specifier
    printf("Test 4: Integer Specifier\n");
    ret_ft_printf = ft_printf("Integer: %d\n", 1234);
    ret_printf = printf("Integer: %d\n", 1234);
    printf("ft_printf return: %d, printf return: %d\n\n", ret_ft_printf, ret_printf);

    // Test with unsigned integer specifier
    printf("Test 5: Unsigned Integer Specifier\n");
    ret_ft_printf = ft_printf("Unsigned Integer: %u\n", 4294967295u);
    ret_printf = printf("Unsigned Integer: %u\n", 4294967295u);
    printf("ft_printf return: %d, printf return: %d\n\n", ret_ft_printf, ret_printf);

    // Test with hexadecimal specifiers (lowercase and uppercase)
    printf("Test 6: Hexadecimal Specifiers\n");
    ret_ft_printf = ft_printf("Hex Lower: %x, Hex Upper: %X\n", 255, 255);
    ret_printf = printf("Hex Lower: %x, Hex Upper: %X\n", 255, 255);
    printf("ft_printf return: %d, printf return: %d\n\n", ret_ft_printf, ret_printf);

    // Test with pointer specifier
    printf("Test 7: Pointer Specifier\n");
    int x = 42;
    ret_ft_printf = ft_printf("Pointer: %p\n", &x);
    ret_printf = printf("Pointer: %p\n", &x);
    printf("ft_printf return: %d, printf return: %d\n\n", ret_ft_printf, ret_printf);

    // Test with percent sign
    printf("Test 8: Percent Sign\n");
    ret_ft_printf = ft_printf("Percentage: %%\n");
    ret_printf = printf("Percentage: %%\n");
    printf("ft_printf return: %d, printf return: %d\n\n", ret_ft_printf, ret_printf);

    // Test with mixed specifiers
    printf("Test 9: Mixed Specifiers\n");
    ret_ft_printf = ft_printf("Char: %c, String: %s, Integer: %d, Unsigned: %u, Hex: %x, Pointer: %p, Percent: %%\n",
        'B', "Mixed test", -42, 123456, 3735928559u, &x);
    ret_printf = printf("Char: %c, String: %s, Integer: %d, Unsigned: %u, Hex: %x, Pointer: %p, Percent: %%\n",
        'B', "Mixed test", -42, 123456, 3735928559u, &x);
    printf("ft_printf return: %d, printf return: %d\n\n", ret_ft_printf, ret_printf);

    // Test edge cases
    printf("Test 10: Edge Cases\n");
    ret_ft_printf = ft_printf("Max Int: %d, Min Int: %d\n", INT_MAX, INT_MIN);
    ret_printf = printf("Max Int: %d, Min Int: %d\n", INT_MAX, INT_MIN);
    printf("ft_printf return: %d, printf return: %d\n\n", ret_ft_printf, ret_printf);

    // Null string test
    printf("Test 11: Null String\n");
    ret_ft_printf = ft_printf("Null String: %s\n", (char *)NULL);
    ret_printf = printf("Null String: %s\n", (char *)NULL);
    printf("ft_printf return: %d, printf return: %d\n\n", ret_ft_printf, ret_printf);

    return 0;
}

