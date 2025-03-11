/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:50:22 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/18 09:50:25 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	a;

	a = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		a = -n;
	}
	if (a > 9)
	{
		ft_putnbr_fd((a / 10), fd);
		ft_putchar_fd((a % 10) + '0', fd);
	}
	else
		ft_putchar_fd(a + '0', fd);
}
