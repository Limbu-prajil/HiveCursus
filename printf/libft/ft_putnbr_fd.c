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

	if (n == INT_MIN)
	{
		if (write(fd, "-2147483648", 11) != 11)
			return (-1);
		return (0);
	}
	if (n < 0)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		n = -n;
	}
	if (n > 9)
	{
		if (ft_putnbr_fd(n / 10, fd) == -1)
			return (-1);
	}
	if (ft_putchar_fd((n % 10) + '0', fd) == -1)
		return (-1);
	return (0);
}
