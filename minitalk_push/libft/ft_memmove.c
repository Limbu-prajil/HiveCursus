/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:23:08 by kjullien          #+#    #+#             */
/*   Updated: 2024/11/07 17:18:19 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	size_t	counter;

	counter = 0;
	if (dest > source)
	{
		while (counter < n)
		{
			*(uint8_t *)(dest + n - 1 - counter) = *(uint8_t *)(source + n - 1
					- counter);
			counter++;
		}
	}
	else if (source > dest)
	{
		while (counter < n)
		{
			*(uint8_t *)(dest + counter) = *(uint8_t *)(source + counter);
			counter++;
		}
	}
	return (dest);
}
