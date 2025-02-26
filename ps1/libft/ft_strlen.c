/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:46:12 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/01 12:53:17 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

//size_t	ft_strlen(const char *s);
//#include <string.h>
//#include <stdio.h>
//void test_string(const char *string)
//{
//	int ref, my;
//	ref = strlen(string);
//	my = ft_strlen(string);
//	if (ref != my)
//		printf("%s\tref=%d\tmy=%d", string, ref, my);
//}
//
//int main(void)
//{
//	test_string("string literal");
//	test_string("a");
//	test_string("");
//	//char constants are of type int! No need to test test_string('');
//	return (0);
//}
//
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len) != '\0')
		len++;
	return (len);
}
