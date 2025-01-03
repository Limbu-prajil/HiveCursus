/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:09:14 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/30 11:09:21 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_verify(const char c, va_list args)
{
	int	size;

	size = 0;
	if (c == 'c')
		size = ft_printf_char(va_arg(args, int));
	else if (c == 's')
		size = ft_printf_string(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		size = ft_printf_nbr(va_arg(args, int));
	else if (c == 'u')
		size = ft_printf_unbr(va_arg(args, unsigned int));
	else if (c == 'x')
		size = ft_printf_hexlow(va_arg(args, unsigned int));
	else if (c == 'X')
		size = ft_printf_hexupp(va_arg(args, unsigned int));
	else if (c == '%')
		size = ft_putchar_fd('%', 1);
	else if (c == 'p')
		size = ft_printf_pointer(va_arg(args, void *));
	return (size);
}

static int	ft_handle_format(const char *str, int *i, va_list args)
{
	int	rtn;

	rtn = ft_verify(str[*i + 1], args);
	if (rtn == -1)
		return (-1);
	*i += 2;
	return (rtn);
}

static int	ft_write(const char *str, va_list args)
{
	int	size;
	int	i;
	int	rtn;

	size = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			rtn = ft_handle_format(str, &i, args);
			if (rtn == -1)
				return (-1);
			size += rtn;
		}
		else
		{
			if (ft_putchar_fd(str[i++], 1) == -1)
				return (-1);
			size++;
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
