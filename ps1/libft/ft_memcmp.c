/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:16:48 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/01 12:46:05 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>
//#include <string.h>
//int ft_memcmp(const void *s1, const void *s2, size_t n);
//void test(const void* lhs, const void* rhs, int sz)
//{
//	int ref = memcmp(lhs, rhs, sz);
//	int my = ft_memcmp(lhs, rhs, sz);
//	if (ref == my)
//		printf("good\n");
//	else
//		printf("error\tref=%d\tmy=%d\n", ref, my);
//}
//
//void demo(const void* lhs, const void* rhs, int sz)
//{
//    const int rc = ft_memcmp(lhs, rhs, sz);
//    if (rc < 0)
//        printf("First %d chars of [%s] precede [%s]\n", sz, lhs, rhs);
//    else if (rc > 0)
//        printf("First %d chars of [%s] follow [%s]\n", sz, lhs, rhs);
//    else
//        printf("First %d chars of [%s] equal [%s]\n", sz, lhs, rhs);
//}
//int main(void)
//{
//    const char* string = "Hello World!";
//    demo(string, "Hello!", 5);
//    demo(string, "Hello Wild!!", 12);
//    demo(string, "Hello there", 10);
//    demo("Hello, everybody!" + 12, "Hello, somebody!" + 11, 5);
//	printf("*****\n");
//    test(string, "Hello!", 5);
//    test(string, "Hello", 10);
//    test(string, "Hello there", 10);
//    test("Hello, everybody!" + 12, "Hello, somebody!" + 11, 5);
//	test(string, "Hello", 0);
//	test("", "", 1);
//	test("", "", 0);
//	//reference function seg faults when given null ptr
//	//test(0, "", 1);
//	//test("", 0, 1);
//	//test(0, 0, 1);
//	//test(0, 0, 0);
//}
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n >= 1)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
