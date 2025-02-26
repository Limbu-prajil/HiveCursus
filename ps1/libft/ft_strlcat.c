/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:25:41 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/01 13:06:10 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
//#include <string.h>
//#include <stdio.h>
//#define BUFLEN 0
//#define BUFCNT {}
//int	main(void)
//{
//	//when BUFLEN zero or dest string not null terminated, i.e., not a proper
//	//string, interchange following two definitions to see that spurious 
//	//characters also appear using reference strlcat function; memory 
//	//arrangement matters
//	char refbuf[BUFLEN] = BUFCNT, mybuf[BUFLEN] = BUFCNT;
//	//char mybuf[BUFLEN] = BUFCNT, refbuf[BUFLEN] = BUFCNT;
//	char src[] = "test12";
//	size_t ref, my, len;
//
//	len = BUFLEN;
//	ref = strlcat(refbuf, src, len);
//	printf("ref:\twanted %lu characters, %s\n", (unsigned long)ref, refbuf);
//	my = ft_strlcat(mybuf, src, len);
//	printf("my:\twanted %lu characters, %s\n\n", (unsigned long)my, mybuf);
//	return(0);
//}
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen + 1 > dstsize)
		dstlen = dstsize;
	dstsize -= dstlen;
	if (srclen + 1 < dstsize)
		dstsize = srclen + 1;
	(void)ft_memcpy (dst + dstlen, src, dstsize);
	if (dstsize > 0)
		*(dst + dstlen + dstsize - 1) = (char) '\0';
	return (dstlen + srclen);
}
