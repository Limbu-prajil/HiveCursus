/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:27:21 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/11 16:27:23 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			total_size;

	total_size = nmemb * size;
	ptr = (unsigned char *)malloc(total_size);
	if (!ptr)
		return (NULL);
	while (total_size--)
	{
		ptr[total_size] = 0;
	}
	return (ptr);
}
