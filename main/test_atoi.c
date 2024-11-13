#include "../libft/libft.h"

void test_ft_atoi() {
    // Basic Valid Integer Strings
    printf("Test '123': %d\n", ft_atoi("123") == 123 ? 1 : 0);
    printf("Test '-456': %d\n", ft_atoi("-456") == -456 ? 1 : 0);

    // Strings with Leading and Trailing Whitespaces
    printf("Test '   789': %d\n", ft_atoi("   789") == 789 ? 1 : 0);
    printf("Test '  -321 ': %d\n", ft_atoi("  -321 ") == -321 ? 1 : 0);

    // Strings with Signs Only
    printf("Test '+': %d\n", ft_atoi("+") == 0 ? 1 : 0);
    printf("Test '-': %d\n", ft_atoi("-") == 0 ? 1 : 0);

    // Mixed Alphanumeric Strings
    printf("Test '123abc': %d\n", ft_atoi("123abc") == 123 ? 1 : 0);
    printf("Test 'abc123': %d\n", ft_atoi("abc123") == 0 ? 1 : 0);
    printf("Test '12.34': %d\n", ft_atoi("12.34") == 12 ? 1 : 0);

    // Overflow and Underflow Scenarios
    printf("Test '2147483648' (Overflow): %d\n", ft_atoi("2147483648") == INT_MAX ? 1 : 0);
    printf("Test '-2147483649' (Underflow): %d\n", ft_atoi("-2147483649") == INT_MIN ? 1 : 0);

    // Boundary Values
    printf("Test '2147483647' (INT_MAX): %d\n", ft_atoi("2147483647") == INT_MAX ? 1 : 0);
    printf("Test '-2147483648' (INT_MIN): %d\n", ft_atoi("-2147483648") == INT_MIN ? 1 : 0);

    // Empty String
    printf("Test '': %d\n", ft_atoi("") == 0 ? 1 : 0);

    // Strings with Only Whitespaces
    printf("Test '    ': %d\n", ft_atoi("    ") == 0 ? 1 : 0);

    // Single Digit Strings
    printf("Test '5': %d\n", ft_atoi("5") == 5 ? 1 : 0);
    printf("Test '-3': %d\n", ft_atoi("-3") == -3 ? 1 : 0);

    // Positive and Negative Zero
    printf("Test '+0': %d\n", ft_atoi("+0") == 0 ? 1 : 0);
    printf("Test '-0': %d\n", ft_atoi("-0") == 0 ? 1 : 0);
}

int main() {
    test_ft_atoi();
    return 0;
}

