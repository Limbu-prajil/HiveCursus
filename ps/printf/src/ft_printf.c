/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                  :+         +:+     */
/*   By: mrudloff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:47:58 by mrudloff          #+#    #+#             */
/*   Updated: 2022/10/30 23:26:03 by mrudloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_case(va_list args, const char frmt)
{
	unsigned long	ptr;

	if (frmt == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (frmt == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (frmt == 'p')
	{
		ptr = va_arg(args, unsigned long);
		if (ptr)
			return (ft_puthexa_u(ptr, frmt));
		return (ft_putstr("(nil)"));
	}
	else if (frmt == 'd' || frmt == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (frmt == 'u')
		return (ft_putunbr_base(va_arg(args, unsigned int), "0123456789"));
	else if (frmt == 'x' || frmt == 'X')
		return (ft_puthexa_u(va_arg(args, unsigned int), frmt));
	else if (frmt == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]) != 0)
		{
			length += ft_case(args, s[i + 1]);
			i++;
		}
		else
			length += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (length);
}
