#include "ft_printf.h"

//%c
//Function to print a character

int	ft_printf_char(char c)
{
	return (ft_putchar_fd(c, 1));
}
