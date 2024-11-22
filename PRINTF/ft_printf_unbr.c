/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:13:43 by lalves-d          #+#    #+#             */
/*   Updated: 2024/10/24 12:40:36 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%u
//Function that counts the number of digits in an unsigned number
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

//Function that prints an unsigned number recursively
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

//Main function that prints an unsigned number and returns the count of digits
int	ft_printf_unbr(unsigned int nb)
{
	if (nb == 0)
		ft_putchar_fd('0', 1);
	else
		ft_positive_putunbr(nb);
	return (get_unsigned_num_size(nb));
}
