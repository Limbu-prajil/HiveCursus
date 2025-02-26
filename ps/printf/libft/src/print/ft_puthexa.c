/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudloff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:11:15 by mrudloff          #+#    #+#             */
/*   Updated: 2022/10/29 22:08:24 by mrudloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_puthexa(long long int n, char format)
{
	const char		*base = "0123456789abcdef";
	int				nbr_len;
	unsigned int	base_len;

	nbr_len = 0;
	if (format == 'p')
	{
		write(1, "0x", 2);
		nbr_len += 2;
	}
	if (format == 'X')
		ft_strcapitalize((char *)base);
	base_len = ft_strlen(base);
	if (n < 0)
		n *= -1;
	if (n >= base_len)
	{
		ft_putunbr_base(n / 16, base);
		ft_putunbr_base(n % 16, base);
	}
	else
		write (1, &base[n], 1);
	nbr_len += ft_unbrlen_base(n, base_len);
	return (nbr_len);
}
