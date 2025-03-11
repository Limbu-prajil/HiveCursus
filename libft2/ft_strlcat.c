/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 10:28:46 by ocassany          #+#    #+#             */
/*   Updated: 2023/02/10 20:18:15 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;

	if (!size)
		return (ft_strlen(src));
	d = 0;
	while (dst[d] && d < size)
		d++;
	s = 0;
	while (src[s] && (d + s) < size - 1)
	{
		dst[d + s] = src[s];
		s++;
	}
	if (d < size)
		dst[d + s] = '\0';
	return (d + ft_strlen(src));
}
