/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:14:59 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/01 13:05:22 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
//#include <string.h>
//#include <stdio.h>
//#define BUFLEN 0
//int	main(void)
//{
//	char refbuf[BUFLEN], mybuf[BUFLEN];
//	char src[] = "test";
//	size_t ref, my, len;
//
//	len = BUFLEN;
//	ref = strlcpy(refbuf, src, len);
//	printf("ref:\twanted %lu characters, %s\n", (unsigned long)ref, refbuf);
//	my = ft_strlcpy(mybuf, src, len);
//	printf("my:\twanted %lu characters, %s\n\n", (unsigned long)my, mybuf);
//	return(0);
//}
////strange behavior when setting BUFLEN = 0 and using the return value
////of ft_memcpy (same with memcpy) instead of its side effect for dst, i.e.,
////dst = ft_memcpy (dst, src, dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < dstsize)
		dstsize = srclen + 1;
	(void)ft_memcpy (dst, src, dstsize);
	if (dstsize > 0)
		*(dst + dstsize - 1) = (char) '\0' ;
	return (srclen);
}
