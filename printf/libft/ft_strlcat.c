/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:52:18 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/18 09:52:20 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ldst;
	size_t	lsrc;
	size_t	cut;
	size_t	res;

	lsrc = ft_strlen(src);
	if (!size)
		return (lsrc);
	ldst = ft_strlen(dst);
	if (ldst >= size)
		return (lsrc + size);
	cut = size - ldst - 1;
	res = ldst + lsrc;
	i = 0;
	while (i < cut && src[i])
	{
		dst[ldst + i] = src[i];
		i++;
	}
	if (cut > 0)
		dst[ldst + i] = '\0';
	return (res);
}
