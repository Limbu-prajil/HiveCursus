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

int	ft_putnbr_fd(int n, int fd)
{
	int	a;
	int	rtn;

	a = n;
	if (a < 0 || a == INT_MIN)
	{
		rtn = ft_putchar_fd('-', fd);
		if (rtn == -1)
			return (-1);
		a = -n;
	}
	if (a > 9)
	{
		if (ft_putnbr_fd((a / 10), fd) == -1)
			return (-1);
		if (ft_putchar_fd((a % 10) + '0', fd) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar_fd(a + '0', fd) == -1)
			return (-1);
	}
	return (0);
}
