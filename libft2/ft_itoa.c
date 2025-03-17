/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:18:41 by kjullien          #+#    #+#             */
/*   Updated: 2024/11/14 22:48:58 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

static char	*ft_handle_zero_and_int_min(int n)
{
	char	*r;

	if (n == 0)
	{
		r = malloc(2 * sizeof(char));
		if (!r)
			return (NULL);
		ft_memcpy(r, "0", 2);
	}
	if (n == INT_MIN)
	{
		r = malloc(12 * sizeof(char));
		if (!r)
			return (NULL);
		ft_memcpy(r, "-2147483648", 12);
	}
	return (r);
}

static void	ft_handle_sign(int *n, int *size, int *sign)
{
	if (*n < 0)
	{
		*size = *size + 1;
		*sign = -1;
		*n = *n * -1;
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

char		*ft_itoa(int n);

char	*ft_itoa(int n)
{
	int		size;
	int		sign;
	char	*r;
	int		counter;

	if (n == 0 || n == INT_MIN)
		return (ft_handle_zero_and_int_min(n));
	sign = 1;
	size = 0;
	ft_handle_sign(&n, &size, &sign);
	size += ft_nbr_size(n);
	r = malloc((size + 1) * sizeof(char));
	if (!r)
		return (NULL);
	counter = size - 1;
	while (n > 0)
	{
		r[counter--] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign == -1)
		r[0] = '-';
	r[size] = '\0';
	return (r);
}
