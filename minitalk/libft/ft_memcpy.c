/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:52:58 by kjullien          #+#    #+#             */
/*   Updated: 2024/11/14 20:19:30 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t	counter;

	if (!s1 && !s2)
		return (NULL);
	counter = 0;
	while (counter < n)
	{
		*(uint8_t *)(s1 + counter) = *(uint8_t *)(s2 + counter);
		counter++;
	}
	return (s1);
}
