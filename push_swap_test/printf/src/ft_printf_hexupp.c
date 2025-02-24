/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexupp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:07:29 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/30 11:07:31 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexupp(unsigned long num)
{
	char	*base;
	int		count;
	int		rtn;

	base = "0123456789ABCDEF";
	count = 0;
	rtn = 0;
	if (num >= 16)
	{
		rtn = ft_printf_hexupp(num / 16);
		if (rtn == -1)
			return (-1);
		count += rtn;
	}
	if (write(1, &base[num % 16], 1) == -1)
		return (-1);
	count++;
	return (count);
}
