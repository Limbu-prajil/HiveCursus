/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexlow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:09:37 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/30 11:09:39 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%x
//Convert a number to a lowercase hexadecimal
int	ft_printf_hexlow(unsigned long long num)
{
	char	*base;
	int		count;
	int		rtn;

	base = "0123456789abcdef";
	count = 0;
	rtn = 0;
	if (num >= 16)
	{
		rtn = ft_printf_hexlow(num / 16);
		if (rtn == -1)
			return (-1);
		count += rtn;
	}
	if (write(1, &base[num % 16], 1) == -1)
		return (-1);
	count++;
	return (count);
}
