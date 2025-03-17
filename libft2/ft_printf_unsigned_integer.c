/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_integer.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:23:39 by kjullien          #+#    #+#             */
/*   Updated: 2024/12/05 22:24:07 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdint.h>
#include <unistd.h>

static int	ft_nbr_size(unsigned int n)
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

static void	ft_itoa_r(unsigned int n, char *r)
{
	int	size;
	int	counter;

	if (n == 0)
	{
		r[0] = '0';
		r[1] = '\0';
		return ;
	}
	size = 0;
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

void	ft_printf_print_unsigned_integer(unsigned int n, int *counter)
{
	char	r[11];
	int		index;

	ft_itoa_r(n, r);
	index = 0;
	while (r[index])
	{
		*counter += (int)write(STDOUT_FILENO, &r[index], 1);
		index++;
	}
}
