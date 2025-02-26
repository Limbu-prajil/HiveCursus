/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:41:31 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/01 12:45:37 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <unistd.h>
//#include <string.h>
//#include <stdio.h>
//#include <stdint.h>
//void *ft_memchr(const void *s, int c, size_t n);
//void test_func(char *string, int c, size_t n)
//{
//	void *ref = memchr(string, c, n);
//	void *my = ft_memchr(string, c, n);
//	if (ref == 0 & my == 0)
//		printf("good\n");
//		//printf("Both ref and my did not find character in string\n");
//	else if (ref != my)
//		printf("Error!\tref=%lu\tmy=%lu\n", (u l)ref, (u l)my);
//}
//int	main(void)
//{
//	//char long_string[SIZE_MAX];
//	char long_string[1000000];
//	char string[15] = "This is a test!";
//	size_t sz = 15;
//	test_func(long_string, '\0', 100000);
//	test_func(string, 'a', sz);
//	test_func(string, '@', sz);
//	test_func(string, '\0', sz);
//	test_func(string, 599, sz);
//	test_func(string, -30, sz);
//	test_func("", 'a', sz);
//	test_func("", '\0', sz);
//	test_func("", '\0', 0);
//	printf("*****\n");
//	const char str[] = "ABCDEFG";
//    const int chars[] = {'D', 'd'};
//    for (size_t i = 0; i < sizeof chars / (sizeof chars[0]); ++i)
//    {
//        const int c = chars[i];   
//        const char *ps = ft_memchr(str, c, strlen(str));
//        ps ? printf ("character '%c'(%i) found: %s\n", c, c, ps)
//           : printf ("character '%c'(%i) not found\n", c, c);
//    }
//	return (0);
//}
////variant used for ft_strchr.c, doesn't work as well for ft_memchr.c
////	while (*(unsigned char *)s != (unsigned char)c)
////	{
////		//printf("%lu ", (unsigned long)n);
////		//write(0, &n, 1);
////		if (n == 1)
////			return (0);
////		s++;
////		n--;
////	}
////	return ((void *)s);
void	*ft_memchr(const void *s, int c, size_t n)
{
	while (1 <= n)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
		n--;
	}
	return (0);
}
