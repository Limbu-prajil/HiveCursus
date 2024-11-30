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
