/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:24:58 by pdietric          #+#    #+#             */
/*   Updated: 2023/10/30 21:18:02 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <string.h>
//#include <stdio.h>
//#include <stdint.h>
//char *ft_strrchr(const char *s, int c);
////both strchr and strrchr segfault when given null pointer for string
//void test_func(char *string, int c)
//{
//	char *ref = strrchr(string, c);
//	char *my = ft_strrchr(string, c);
//	if (ref == 0 & my == 0)
//		printf("Both ref and my did not find character in string\n");
//	else if (ref != my)
//		printf("Error!\t%s\tref=%lu\tmy=%lu\n", string,	(u l) ref, (u l) my);
//	else printf("good\n");
//}
//int	main(void)
//{
//	//char long_string[SIZE_MAX];
//	char long_string[1000000];
//	test_func(long_string, '\0');
//	test_func("This is a test!", 'a');
//	test_func("This is a test!", '@');
//	test_func("This is a test!", '\0');
//	test_func("This is a test!", 599);
//	test_func("This is a test!", -30);
//	test_func("", 'a');
//	test_func("", '\0');
//	test_func(0, 'a');
//	return (0);
//}
////***first variant, thought it is elegant***
////char *ft_strrchr(const char *s, int c)
////{
////	char *last_occ;
////	char *occ;
////
////	occ = ft_strchr(s, c);
////	last_occ = occ;
////	while (occ != 0 & c != '\0')
////	{
////		last_occ = occ;
////		occ = ft_strchr(s++, c);
////	}
////	return (last_occ);
////}
char	*ft_strrchr(const char *s, int c)
{
	const char	*start;

	start = s;
	while (*s != '\0')
		s++;
	while (*s != (char)c)
	{
		if (s == start)
			return (0);
		s--;
	}
	return ((char *)s);
}
