/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:44:43 by pdietric          #+#    #+#             */
/*   Updated: 2023/10/24 21:31:21 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//char	*ft_strjoin(char const *s1, char const *s2);
//#include <stdio.h>
//#include <string.h>
//void	test(char const *s1, char const *s2)
//{
//	char *s3 = ft_strjoin(s1, s2);
//	printf("%s\n", s3);
//	free(s3);
//}
//int main(void)
//{
//	test("_ABCD_", "_abcd_");
//	test("_ABCD_", "");
//	test("", "_abcd_");
//	test("", "");
//	return (0);
//}
////No need to store lengths of s1 and s2 separately, one var size does it,
////because ft_strlcat (and, of course, strlcat) look for string terminator
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(size + 1);
	if (p != 0)
	{
		(void)ft_strlcpy(p, s1, size + 1);
		(void)ft_strlcat(p, s2, size + 1);
	}
	return (p);
}
