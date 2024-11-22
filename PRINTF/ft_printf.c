/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:07:39 by lalves-d          #+#    #+#             */
/*   Updated: 2024/10/24 11:20:05 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_verify(char c, va_list args)
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
	{
		ft_putchar_fd('%', 1);
		size = 1;
	}
	else if (c == 'p')
		size = ft_printf_pointer(va_arg(args, void *));
	return (size);
}

static int	ft_write(const char *s, va_list args)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			size += ft_verify(s[i + 1], args);
			i += 2;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
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
