/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:43:40 by pdietric          #+#    #+#             */
/*   Updated: 2023/10/30 20:35:26 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//char	*ft_strtrim(char const *s1, char const *set);
//#include <stdio.h>
//#include <string.h>
//void	test(char const *s1, char const *set)
//{
//	char *s3 = ft_strtrim(s1, set);
//	printf("%s\n", s3);
//	free(s3);
//}
//int main(void)
//{
//	test("_ABCD_", "_");
//	test("-_-__ABCDEFG-IJKL_MN-___-", "-_");
//	test("-_-__ABCDEFG-IJKL_MN-___-", "_-");
//	test("-_-__ABCDEFG-IJKL_MN-___-", "");
//	test("", "_abcd_");
//	test("", "");
//	test("lorem \n ipsum \t dolor \n sit \t amet", " ");
//	return (0);
//}
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	l;
	size_t	r;
	char	*p;

	l = 0;
	r = ft_strlen(s1);
	while (ft_strchr(set, *(s1 + l)))
	{
		if (*(s1 + l) == '\0')
			break ;
		l++;
	}
	if (l < r)
		while (ft_strchr(set, *(s1 + r - 1)))
			r--;
	p = malloc(r - l + 1);
	if (p)
		ft_strlcpy(p, s1 + l, r - l + 1);
	return (p);
}
