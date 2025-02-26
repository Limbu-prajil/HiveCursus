/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:32:32 by kjullien          #+#    #+#             */
/*   Updated: 2024/11/14 22:29:58 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	counter;
	size_t	src_size;
	size_t	dst_size;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	if (size <= 0)
		return (src_size);
	if (src_size == 0)
		return (dst_size);
	counter = dst_size;
	while (counter < size - 1 && src[counter - dst_size])
	{
		dst[counter] = src[counter - dst_size];
		counter++;
	}
	if (dst_size > size)
		return (src_size + size);
	dst[counter] = '\0';
	return (dst_size + src_size);
}
