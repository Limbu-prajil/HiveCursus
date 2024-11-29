#include "ft_printf.h"

//%x
//Convert a number to a lowercase hexadecimal
int	ft_printf_hexlow(unsigned int num)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (num >= 16)
	{
		count += ft_printf_hexlow(num / 16);
	}
	count += write(1, &base[num % 16], 1);
	return (count);
}
