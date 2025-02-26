/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:58:42 by ocassany          #+#    #+#             */
/*   Updated: 2023/08/14 18:28:45 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(long int n)
{
	int			nbr_chr;

	nbr_chr = 0;
	if (n < 0)
	{
		nbr_chr++;
		n = n * -1;
	}
	while (n > 9)
	{
		nbr_chr++;
		n /= 10;
	}
	nbr_chr++;
	return (nbr_chr);
}

char	*ft_itoa(int n)
{
	char		*tab;
	int			nbr_chr;
	long int	num;

	num = n;
	nbr_chr = n_len(num);
	if (n == 0)
		return (ft_strdup("0"));
	tab = malloc((nbr_chr + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	tab[nbr_chr] = '\0';
	if (num < 0)
	{
		tab[0] = '-';
		num *= -1;
	}
	while (nbr_chr > 0 && num > 0)
	{
		tab[nbr_chr - 1] = (num % 10) + '0';
		num /= 10;
		nbr_chr--;
	}
	return (tab);
}
