#include "libft.h"

long ft_atol(const char *str) {
    long result = 0;
    int sign = 1;

    // Skip whitespace
    while (*str == ' ' || (*str >= '\t' && *str <= '\r')) {
        str++;
    }

    // Handle optional sign
    if (*str == '+' || *str == '-') {
        if (*str == '-') {
            sign = -1;
        }
        str++;
    }

    // Convert digits to integer
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}
