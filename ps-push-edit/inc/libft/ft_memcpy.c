/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:48:16 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/18 09:48:23 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destt;
	char	*ssrc;

	destt = (char *)dest;
	ssrc = (char *)src;
	if (ssrc == destt)
		return (dest);
	i = 0;
	while (i < n)
	{
		destt[i] = ssrc[i];
		i++;
	}
	return (dest);
}
