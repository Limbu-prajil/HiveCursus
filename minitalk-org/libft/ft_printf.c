/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:18:37 by plimbu            #+#    #+#             */
/*   Updated: 2025/03/21 14:18:40 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_printstr(char *str)
{
	int	i;

	if (!str)
		return (ft_printstr("(null)"));
	i = 0;
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}

int	ft_ptnbr(long long nbr, char c, int len_base)
{
	char	*base;
	int		len;

	if (c == 'X' || c == 'i' || c == 'd' || c == 'u')
		base = "0123456789ABCDEF";
	else if (c == 'x')
		base = "0123456789abcdef";
	len = 0;
	if (nbr < 0)
	{
		len += write(1, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr > (len_base -1))
	{
		len += ft_ptnbr(nbr / len_base, c, len_base);
		len += ft_ptnbr(nbr % len_base, c, len_base);
	}
	else
		len += write(1, &base[nbr], 1);
	return (len);
}

int	ft_ptnbrptr(unsigned long long nbr, char c, int len_base)
{
	char				*base;
	int					len;
	unsigned long long	len_base_ptr;

	base = "0123456789abcdef";
	len = 0;
	len_base_ptr = (unsigned long long)len_base;
	if (nbr > (len_base_ptr - 1))
	{
		len += ft_ptnbrptr(nbr / len_base_ptr, c, len_base);
		len += ft_ptnbrptr(nbr % len_base_ptr, c, len_base);
	}
	else
		len += write(1, &base[nbr], 1);
	return (len);
}

int	find_value(char f, va_list args)
{
	unsigned long long	p;

	if (f == 'c')
		return (f = va_arg(args, int), write(1, &f, 1));
	else if (f == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (f == 'p')
	{
		p = (unsigned long long)va_arg(args, void *);
		if (!p)
			return (ft_printstr("(nil)"));
		return (ft_printstr("0x") + ft_ptnbrptr(p, f, 16));
	}
	else if (f == 'd' || f == 'i')
		return (ft_ptnbr((va_arg(args, int)), f, 10));
	else if (f == 'u')
		return (ft_ptnbr((va_arg(args, unsigned int)), f, 10));
	else if (f == 'x' || f == 'X')
		return (ft_ptnbr((va_arg(args, unsigned int)), f, 16));
	else if (f == '%')
		return (ft_printstr("%"));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != '%')
			len += write(1, &str[i], 1);
		else
		{
			i++;
			len += find_value(str[i], args);
		}
		i++;
	}
	va_end(args);
	return (len);
}
