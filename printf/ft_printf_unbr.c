/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:08:54 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/30 11:08:57 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_unsigned_num_size(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static void	ft_positive_putunbr(unsigned int n)
{
	if (n <= 9)
	{
		n = n + '0';
		ft_putchar_fd(n, 1);
	}
	else
	{
		ft_positive_putunbr(n / 10);
		ft_positive_putunbr(n % 10);
	}
}

int	ft_printf_unbr(unsigned int nb)
{
	if (nb == 0)
		ft_putchar_fd('0', 1);
	else
		ft_positive_putunbr(nb);
	return (get_unsigned_num_size(nb));
}
