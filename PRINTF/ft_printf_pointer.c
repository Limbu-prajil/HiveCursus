/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:08:06 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/30 11:08:15 by plimbu           ###   ########.fr       */
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
