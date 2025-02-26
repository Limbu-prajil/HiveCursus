/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudloff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:50:29 by mrudloff          #+#    #+#             */
/*   Updated: 2022/10/27 11:43:15 by mrudloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]) > 0)
			return (1);
		if ((((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}
