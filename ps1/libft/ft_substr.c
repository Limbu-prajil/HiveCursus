/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:51:28 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/01 12:35:28 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "string.h"
//char	*ft_substr(char const *s, unsigned int start, size_t len);
//#include <stdio.h>
//int main (void)
//{
//	//char			*s = "_aaaa_";
//	char			*s = "hola";
//	//char			*s = "";
//	unsigned int 	i = 0;
//	unsigned int	l = 7;
//
//	printf("\"%s\", pos %i, length %i: %s\n", s, i, l, ft_substr(s, i, l));
//	i=0; l=0;
//	printf("\"%s\", pos %i, length %i: %s\n", s, i, l, ft_substr(s, i, l));
//	i=0; l=6;
//	printf("\"%s\", pos %i, length %i: %s\n", s, i, l, ft_substr(s, i, l));
//	i=0; l=5;
//	printf("\"%s\", pos %i, length %i: %s\n", s, i, l, ft_substr(s, i, l));
//	i=0; l=10;
//	printf("\"%s\", pos %i, length %i: %s\n", s, i, l, ft_substr(s, i, l));
//	i=2; l=7;
//	printf("\"%s\", pos %i, length %i: %s\n", s, i, l, ft_substr(s, i, l));
//	i=2; l=7;
//	printf("\"%s\", pos %i, length %i: %i\n", s, i, l, *ft_substr(s, i, l));
//	i=6; l=1;
//	printf("\"%s\", pos %i, length %i: %s\n", s, i, l, ft_substr(s, i, l));
//	i=6; l=0;
//	printf("\"%s\", pos %i, length %i: %s\n", s, i, l, ft_substr(s, i, l));
//	i=7; l=1;
//	printf("\"%s\", pos %i, length %i: %s\n", s, i, l, ft_substr(s, i, l));
//	i=7; l=0;
//	printf("\"%s\", pos %i, length %i: %s\n", s, i, l, ft_substr(s, i, l));
//	i=8; l=1;
//	printf("\"%s\", pos %i, length %i: %s\n", s, i, l, ft_substr(s, i, l));
//	i=8; l=0;
//	printf("\"%s\", pos %i, length %i: %s\n", s, i, l, ft_substr(s, i, l));
//	i=4294967295; l=0;
//	printf("\"%s\", pos %u, length %i: %s\n", s, i, l, ft_substr(s, i, l));
//	return (0);
//}
//
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	len_actual;

	len_actual = ft_strlen(s);
	if (start >= len_actual)
	{
		len = 0;
		start = 0;
	}
	else if (start + len > len_actual)
		len = len_actual - start;
	ptr = malloc(len + 1);
	if (ptr != 0)
		ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}
