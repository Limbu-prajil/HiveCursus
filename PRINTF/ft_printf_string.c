#include "ft_printf.h"

//%s
//Function to print a string

int	ft_printf_string(char *s)
{
	if (!s)
		return (ft_printf_string("(null)"));
	if (ft_putstr_fd(s, 1) == -1)
		return (-1);
	return (ft_strlen(s));
}
