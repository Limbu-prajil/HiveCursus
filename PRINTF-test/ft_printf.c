#include "ft_printf.h"

static int	ft_print_counter(const char c, va_list args)
{
	int	size;

	size = 0;
	if (c == 'c')
		//char arguments are automatically promoted to int when passed to variadic funcs.
		//Meaning actual type of the argument in the variadic function is int not char.
		size = ft_printf_char((char) va_arg(args, int)); // Advances the VAL and retrieves the next argument from the VAL.
	else if (c == 's')
		size = ft_printf_string(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		size = ft_printf_nbr(va_arg(args, int));
	else if (c == 'u')
		size = ft_printf_unbr(va_arg(args, unsigned int));
	else if (c == 'x')
		size = ft_printf_hexlow(va_arg(args, unsigned long long));
	else if (c == 'X')
		size = ft_printf_hexupp(va_arg(args, unsigned long long));
	else if (c == '%')
		size = ft_putchar_fd('%', 1);
	else if (c == 'p')
		size = ft_printf_pointer(va_arg(args, void *));
	return (size);
}

static int	ft_char_checker(const char c)
{
	char	alwd_chars[9];
	int		i;

	i = 0;
	alwd_chars[0] = 'c';
	alwd_chars[1] = 's';
	alwd_chars[2] = 'p';
	alwd_chars[3] = 'd';
	alwd_chars[4] = 'i';
	alwd_chars[5] = 'u';
	alwd_chars[6] = 'x';
	alwd_chars[7] = 'X';
	alwd_chars[8] = '%';
	while (i < 9)
	{
		if (c == alwd_chars[i])
			return (0);
		i++;
	}
	return (-1);
}

static int	ft_format_handler(const char *s, int *i, va_list args)
{
	int	rtn;

	if (ft_char_checker(s[*i + 1]) == -1)
		return (-1);
	rtn = ft_print_counter(s[*i + 1], args);
	if (rtn == -1)
		return (-1);
	*i += 2;
	return (rtn);
}

static int	ft_write(const char *s, va_list args)
{
	int	size;
	int	i;
	int	rtn;

	size = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '\0' && s[i + 1] != ' ')
		{
			rtn = ft_format_handler(s, &i, args);
			if (rtn == -1)
				return (-1);
			size += rtn;
		}
		else
		{
			if (ft_putchar_fd(s[i++], 1) == -1)
				return (-1);
			size++;
		}
	}
	return (size);
}

int	ft_printf(const char *s, ...)
{
	int		size;
	va_list	args; // a type that holds info about the location of the next argument in VAL

	if (!s)
		return (-1);
	if (!ft_strchr(s, '%'))
		return (ft_printf_string((char *)s));
	va_start(args, s); // Initialise the VAL with provided format
	size = ft_write(s, args);
	va_end(args); // Reset the info in va_list
	return (size);
}
