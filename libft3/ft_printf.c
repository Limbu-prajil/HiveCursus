/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:19:37 by kjullien          #+#    #+#             */
/*   Updated: 2024/12/05 22:23:48 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>

static void	ft_printf_print_char(char c, int *counter)
{
	*counter += (int)write(STDOUT_FILENO, &c, 1);
}

static void	ft_printf_print_str(char *str, int *counter)
{
	if (str == NULL)
	{
		*counter += (int)write(STDOUT_FILENO, "(null)", 6);
		return ;
	}
	while (*str)
	{
		*counter += (int)write(STDOUT_FILENO, str, 1);
		str++;
	}
}

static void	ft_printf_handle(va_list args, char next_char, int *counter)
{
	if (next_char == 'c')
		ft_printf_print_char(va_arg(args, int), counter);
	else if (next_char == 's')
		ft_printf_print_str(va_arg(args, char *), counter);
	else if (next_char == 'p')
		ft_printf_print_pointer(va_arg(args, uintptr_t), counter);
	else if (next_char == 'd' || next_char == 'i')
		ft_printf_print_integer(va_arg(args, int), counter);
	else if (next_char == 'u')
		ft_printf_print_unsigned_integer(va_arg(args, unsigned int), counter);
	else if (next_char == 'x')
		ft_printf_print_hexadecimal(va_arg(args, unsigned int), counter, 0);
	else if (next_char == 'X')
		ft_printf_print_hexadecimal(va_arg(args, unsigned int), counter, 1);
	else if (next_char == '%')
		ft_printf_print_char('%', counter);
	else
	{
		ft_printf_print_char('%', counter);
		ft_printf_print_char(next_char, counter);
	}
}

int	ft_printf(const char *msg, ...)
{
	va_list	args;
	size_t	index;
	int		counter;

	counter = 0;
	index = 0;
	va_start(args, msg);
	while (msg[index])
	{
		if (msg[index] == '%')
		{
			index++;
			ft_printf_handle(args, msg[index], &counter);
		}
		else
		{
			counter += (int)write(STDOUT_FILENO, &msg[index], 1);
		}
		index++;
	}
	va_end(args);
	return (counter);
}
