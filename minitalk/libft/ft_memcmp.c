/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:43:36 by kjullien          #+#    #+#             */
/*   Updated: 2024/11/13 00:26:15 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	counter;

	if (n == 0)
		return (0);
	counter = 0;
	while (counter < n - 1 && *(unsigned char *)(s1
		+ counter) == *(unsigned char *)(s2 + counter))
	{
		counter++;
	}
	return (*(unsigned char *)(s1 + counter) - *(unsigned char *)(s2
			+ counter));
}
