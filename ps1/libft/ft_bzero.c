/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:18:24 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/01 13:02:58 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void *ft_bzero(void *b, int c, size_t len);
//#include <string.h>
//#include <stdio.h>
//
//void test(int c, size_t len)
//{
//	char b1[] = "This is another test!";
//	char b2[] = "This is another test!";
//	prntf("ref:\t%s\nmy:\t%s\n\n", (chr*)bz(b1, c, l), (chr*)ft_bz(b2, c, l)); 
//}
//
//int main (void)
//{
//	test('5', 0);
//	test('5', 5);
//	test(0, 5);
//	test(-5, 5);
//	return (0);
//}
//
void	*ft_bzero(void *s, size_t n)
{
	return (ft_memset(s, 0, n));
}
