/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:42:23 by lalves-d          #+#    #+#             */
/*   Updated: 2024/10/24 13:21:15 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%p
//Function that prints a pointer in hexadecimal format
int	ft_printf_pointer(void *ptr)
{
	unsigned long long	address;
	int					count;

	address = (unsigned long long)ptr;
	write(1, "0x", 2);
	count = 2;
	if (address == 0)
	{
		write(1, "(nil)", 5);
		return (count + 5);
	}
	count += ft_printf_hexlow(address);
	return (count);
}
