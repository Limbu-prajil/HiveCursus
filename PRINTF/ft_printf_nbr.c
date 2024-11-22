/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:58:02 by lalves-d          #+#    #+#             */
/*   Updated: 2024/10/24 13:59:34 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%d e %i
//Print an integer decimal number

static int	get_size(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

int	ft_printf_nbr(int nb)
{
	ft_putnbr_fd(nb, 1);
	if (nb == 0)
		return (1);
	return (get_size(nb));
}
