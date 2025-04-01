/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:49:57 by ashobajo          #+#    #+#             */
/*   Updated: 2024/05/24 10:32:00 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	i = 0;
	dst_ptr = (unsigned char *) dst;
	src_ptr = (const unsigned char *) src;
	if (dst_ptr == src_ptr)
		return (dst);
	if (src_ptr < dst_ptr)
	{
		while (n--)
		{
			dst_ptr[n] = src_ptr[n];
		}
	}
	else
	{
		while (i < n)
		{
			dst_ptr[i] = src_ptr[i];
			i++;
		}
	}
	return (dst);
}
