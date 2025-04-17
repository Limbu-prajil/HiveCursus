/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:38:52 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/18 09:41:14 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *c)
{
	int					i;
	int					r;
	long long			result;

	i = 0;
	r = 1;
	result = 0;
	while ((c[i] == '\n' || c[i] == '\r' || c[i] == ' ' || c[i] == '\t'
			|| c[i] == '\v' || c[i] == '\f') && c[i])
		i++;
	if (c[i] == '-')
		r = -1;
	if (c[i] == '-' || c[i] == '+')
		i++;
	while (c[i] >= '0' && c[i] <= '9')
	{
		if (result < 0 && r == -1)
			return (0);
		if (result < 0 && r == 1)
			return (-1);
		result *= 10;
		result += c[i] - '0';
		i++;
	}
	return (r * result);
}
