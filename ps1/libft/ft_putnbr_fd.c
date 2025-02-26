/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:47:54 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/01 19:12:57 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
//void	ft_putnbr_fd(int n, int fd)
//{
//	char	*s;
//
//	s = ft_itoa(n);
//	if (s)
//	{
//		write(fd, s, ft_strlen(s));
//		free(s);
//	}
//}
void	ft_putnbr_fd(int n, int fd)
{
	int		sign;
	char	c[10];
	int		i;

	i = 0;
	sign = 1;
	if (n < 0)
		sign = -1;
	if (n == 0)
		write(fd, "0", 1);
	while (n != 0)
	{
		c[i] = sign * (n % 10) + '0';
		n = n / 10;
		i = i + 1;
	}
	if (sign == -1)
		write (fd, "-", 1);
	while (i > 0)
	{
		i = i - 1;
		write (fd, c + i, 1);
	}
}
