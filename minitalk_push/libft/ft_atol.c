#include "libft.h"

long ft_atol(const char *str)
{
    long result = 0;
    int sign = 1;

    while (*str == ' ' || (*str >= '\t' && *str <= '\r')) {
        str++;
    }
    if (*str == '+' || *str == '-') {
        if (*str == '-') {
            sign = -1;
        }
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result * sign;
}
