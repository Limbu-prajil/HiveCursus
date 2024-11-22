/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexupp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:37:25 by lalves-d          #+#    #+#             */
/*   Updated: 2024/10/24 11:57:17 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%X
//Convert a number to a uppercase hexadecimal

int	ft_printf_hexupp(unsigned int num)
{
	char	*base;
	int		count;

	base = "0123456789ABCDEF";
	if (num >= 16)
	{
		count = ft_printf_hexupp(num / 16) + write(1, &base[num % 16], 1);
		return (count);
	}
	return (write(1, &base[num], 1));
}
