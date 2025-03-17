/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:15:41 by kjullien          #+#    #+#             */
/*   Updated: 2024/11/14 22:34:17 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void	ft_handle_zero_or_int_max(int n, char *r)
{
	if (n == 0)
	{
		r[0] = '0';
		r[1] = '\0';
	}
	if (n == INT_MIN)
	{
		r[0] = '-';
		r[1] = '2';
		r[2] = '1';
		r[3] = '4';
		r[4] = '7';
		r[5] = '4';
		r[6] = '8';
		r[7] = '3';
		r[8] = '6';
		r[9] = '4';
		r[10] = '8';
		r[11] = '\0';
	}
}

static int	ft_nbr_size(int n)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ft_itoa_r(int n, char *r)
{
	int	size;
	int	counter;

	if (n == 0)
		return (ft_handle_zero_or_int_max(n, r));
	if (n == INT_MIN)
		return (ft_handle_zero_or_int_max(n, r));
	size = 0;
	if (n < 0)
	{
		n = n * -1;
		r[0] = '-';
		size++;
	}
	size += ft_nbr_size(n);
	counter = size - 1;
	while (n > 0)
	{
		r[counter--] = (n % 10) + '0';
		n = n / 10;
	}
	r[size] = '\0';
	return ;
}

void		ft_putnbr_fd(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	char	r[12];
	int		counter;

	ft_itoa_r(n, r);
	counter = 0;
	while (r[counter])
	{
		ft_putchar_fd(r[counter], fd);
		counter++;
	}
}
