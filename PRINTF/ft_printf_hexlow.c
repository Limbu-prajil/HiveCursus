/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexlow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:27:08 by lalves-d          #+#    #+#             */
/*   Updated: 2024/10/24 11:35:12 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%x
//Convert a number to a lowercase hexadecimal
int	ft_printf_hexlow(unsigned long long num)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (num >= 16)
	{
		count += ft_printf_hexlow(num / 16);
	}
	count += write(1, &base[num % 16], 1);
	return (count);
}
