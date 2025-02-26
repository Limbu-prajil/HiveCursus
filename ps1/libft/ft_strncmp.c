/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:53:50 by pdietric          #+#    #+#             */
/*   Updated: 2023/10/30 21:32:23 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>
//#include <string.h>
//int ft_strncmp(const char *s1, const char *s2, size_t n);
//void test(const char* lhs, const char* rhs, int sz)
//{
//	int ref = strncmp(lhs, rhs, sz);
//	int my = ft_strncmp(lhs, rhs, sz);
//	if (ref == my)
//		printf("good\n");
//	else
//		printf("error\n");
//}
//
//void demo(const char* lhs, const char* rhs, int sz)
//{
//    const int rc = ft_strncmp(lhs, rhs, sz);
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
//    demo(string, "Hello", 10);
//    demo(string, "Hello there", 10);
//    demo("Hello, everybody!" + 12, "Hello, somebody!" + 11, 5);
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
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (*s1 == '\0')
			break ;
		s1++;
		s2++;
		n--;
	}
	return (0);
}
