/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:23:51 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/01 12:49:18 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void *ft_memset(void *b, int c, size_t len);
//#include <string.h>
//#include <stdio.h>
//
//void test(int c, size_t len)
//{
//	char b1[] = "This is another test!";
//	char b2[] = "This is another test!";
//	prtf("ref:\t%s\nmy:\t%s\n\n", (chr*)ms(b1, c, len), (chr*)ft_ms(b2, c, l)); 
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
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)b + i) = (unsigned char) c;
		i++;
	}
	return (b);
}
