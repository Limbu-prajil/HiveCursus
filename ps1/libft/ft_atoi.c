/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 09:58:36 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/10 14:39:23 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//int	ft_atoi(const char *str);
//#include <stdio.h>
//#include <stdlib.h>
//void test (const char *str)
//{
//	printf("str: %s\t\tref: %i\tmy: %i\n", str, atoi(str), ft_atoi(str));
//}
//int main(void)
//{
//	test("\t  2147483647");
//	test("2147483647");
//	test("-21474836478");
//	test("-21474836479");
//	test("21474836479");
//	test("a123");
//	test("-a123");
//	test("0");
//	test("-0");
//	test("+0");
//	test("-");
//	test("");
//	test((char *)0);//both atoi and ft_atoi segfault here
//	return (0);
//}
//
int	ft_atoi(const char *str)
{
	int		sgn;
	long	val;

	sgn = 1;
	val = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || \
		*str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		sgn = 44 - *str++;
	while (ft_isdigit(*str))
		val = 10 * val + *str++ - '0';
	val *= sgn;
	return ((int)val);
}
