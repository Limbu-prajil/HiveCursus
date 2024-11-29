#include "ft_printf.h"

static int	ft_verify(char c, va_list args)
{
	int	size;

	size = 0;
	if (c == 'c')
		size = ft_printf_char(va_arg(args, int));
		return (size);
	else if (c == 's')
		size = ft_printf_string(va_arg(args, char *));
		return (size);
	else if (c == 'd' || c == 'i')
		size = ft_printf_nbr(va_arg(args, int));
		return (size);
	else if (c == 'u')
		size = ft_printf_unbr(va_arg(args, unsigned int));
		return (size);
	else if (c == 'x')
		size = ft_printf_hexlow(va_arg(args, unsigned int));
		return (size);
	else if (c == 'X')
		size = ft_printf_hexupp(va_arg(args, unsigned int));
		return (size);
	else if (c == '%')
		size = ft_putchar_fd('%', 1);
		return (size);
	else if (c == 'p')
		size = ft_printf_pointer(va_arg(args, void *));
	else
		return (size);
}

static int	ft_check()

static int	ft_write(const char *s, va_list args)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = 0;
	rtn = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			s = s[i + 1];
			if (!s || s == ' ' || s != 'c' || s != 's' || s != 'd'
				|| s != 'i' || s != 'u' || s != 'x' || s != 'X'
					|| s != '%' || s != 'p')
				return (-1);
			rtn = ft_verify(s[i + 1], args);
			if (rtn == -1)
				return (-1);
			size += rtn;
			i += 2;
		}
		else
		{
			rtn = ft_putchar_fd(s[i], 1);
			if (rtn == -1)
				return (-1);
			size++;
			i++;
		}
	}
	return (size);
}

int	ft_printf(const char *s, ...)
{
	int		size;
	va_list	args;

	if (!s)
		return (-1);
	if (!ft_strchr(s, '%'))
		return (ft_printf_string((char *)s));
	va_start(args, s);
	size = ft_write(s, args);
	va_end(args);
	return (size);
}
