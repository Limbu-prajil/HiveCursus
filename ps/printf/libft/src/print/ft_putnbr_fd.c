/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudloff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:25:09 by mrudloff          #+#    #+#             */
/*   Updated: 2022/10/30 00:11:02 by mrudloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_putnbr_fd(long long int n, int fd)
{
	const char	*base = "0123456789";
	int			nbr_len;

	nbr_len = 0;
	if (n == LLONG_MIN)
	{
		write(1, "-9223372036854775807", 20);
		return (20);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr_len += ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	else
		write (fd, &base[n], 1);
	nbr_len += ft_nbrlen_base(n, ft_strlen(base));
	return (nbr_len);
}
