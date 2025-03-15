/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:33:05 by kjullien          #+#    #+#             */
/*   Updated: 2024/11/14 22:27:33 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static int	ft_issign(const char c)
{
	if (c == '-' || c == '+')
	{
		return (1);
	}
	return (0);
}

static int	ft_isspace(const char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
	{
		return (1);
	}
	return (0);
}

int			ft_atoi(const char *nptr);

int	ft_atoi(const char *nptr)
{
	int		total;
	size_t	counter;
	int		sign;

	sign = 1;
	counter = 0;
	total = 0;
	while (ft_isspace(nptr[counter]))
	{
		counter++;
	}
	if (ft_issign(nptr[counter]))
	{
		if (nptr[counter] == '-')
		{
			sign = -1;
		}
		counter++;
	}
	while (ft_isdigit(nptr[counter]))
	{
		total = total * 10 + (nptr[counter] - '0');
		counter++;
	}
	return (total * sign);
}
