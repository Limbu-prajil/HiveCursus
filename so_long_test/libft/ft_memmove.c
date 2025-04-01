/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:48:38 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/18 09:48:44 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*srcc;
	unsigned char	*dstt;
	size_t			i;

	srcc = (unsigned char *)src;
	dstt = (unsigned char *)dest;
	if (dstt == srcc || len == 0)
		return (dest);
	i = -1;
	if (srcc > dstt)
	{
		while (len > ++i)
			dstt[i] = srcc[i];
	}
	else
	{
		while (len)
		{
			dstt[len - 1] = srcc[len - 1];
			len--;
		}
	}
	return (dest);
}
