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
	int					hex_count;

	address = (unsigned long long)ptr;
	count = 0;
	if (address == 0)
	{
		if (write(1, "(nil)", 5) != 5)
			return (-1);
		return (count + 5);
	}
	if (write(1, "0x", 2) != 2)
		return (-1);
	count += 2;
	hex_count = ft_printf_hexlow(address);
	if (hex_count == -1)
		return (-1);
	count += hex_count;
	return (count);
}
