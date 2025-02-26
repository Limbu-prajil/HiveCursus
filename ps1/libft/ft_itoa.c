/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:15:04 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/01 15:43:10 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//char	*ft_itoa(int n);
//#include <stdio.h>
//
////void	ft_putnbr(int nb)
////{
////	int		factor;
////	char	c[10];
////	int		i;
////
////	i = 0;
////	factor = 1;
////	if (nb < 0)
////		factor = -1;
////	if (nb == 0)
////		write(1, "0", 1);
////	while (nb != 0)
////	{
////		c[i] = factor * (nb % 10) + '0';
////		nb = nb / 10;
////		i = i + 1;
////	}
////	if (factor == -1)
////		write (1, "-", 1);
////	while (i > 0)
////	{
////		i = i - 1;
////		write (1, c + i, 1);
////	}
////}
//
//int	main(void)
//{
//	int i = 500;
//	printf("%i\t%s\n", i, ft_itoa(i));
//	i = 0;
//	printf("%i\t%s\n", i, ft_itoa(i));
//	i = -5;
//	printf("%i\t%s\n", i, ft_itoa(i));
//	i = 2147483647;
//	printf("%i\t%s\n", i, ft_itoa(i));
//	i = 2147483648;
//	printf("%i\t%s\n", i, ft_itoa(i));
//	i = -2147483648;
//	printf("%i\t%s\n", i, ft_itoa(i));
//	i = -2147483649;
//	printf("%i\t%s\n", i, ft_itoa(i));
//	return (0);
//}
//
////use my Piscine solution from ex07 of C00
///malloc(len + (1 - sign) / 2 + 1) allocates 2 or 1 more bytes, depending
///on whether the number is negative or positive, respectively
unsigned int	reverse_num(int n, char *ary)
{
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if (n < 0)
		sign = -1;
	if (n == 0)
	{
		*ary = '0';
		i = 1;
	}
	while (n != 0)
	{
		ary[i++] = sign * (n % 10) + '0';
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		sign;
	char	ary[10];
	int		len;
	char	*output;
	char	*output_orig;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = reverse_num(n, ary);
	output_orig = malloc(len + (1 - sign) / 2 + 1);
	if (output_orig)
	{
		output = output_orig;
		if (sign == -1)
			*output++ = '-';
		while (len-- > 0)
			*output++ = ary[len];
		*output = '\0';
	}
	return (output_orig);
}
