/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:09:46 by kjullien          #+#    #+#             */
/*   Updated: 2024/11/19 11:02:30 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	counter;
	size_t	little_len;
	size_t	big_len;

	big_len = ft_strlen(big);
	(void) big_len;
	if (little[0] == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	if (len < little_len)
		return (NULL);
	counter = 0;
	while (counter <= len - little_len && big[counter])
	{
		if (ft_strncmp(big + counter, little, little_len) == 0)
		{
			return ((char *)(big + counter));
		}
		counter++;
	}
	return (NULL);
}
