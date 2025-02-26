/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:39:20 by kjullien          #+#    #+#             */
/*   Updated: 2024/11/15 00:47:41 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c);

char	*ft_strchr(const char *s, int c)
{
	size_t	counter;

	counter = 0;
	while (s[counter])
	{
		if (s[counter] == (unsigned char)c)
		{
			return ((char *)(s + counter));
		}
		counter++;
	}
	if (s[counter] == '\0' && (unsigned char)c == '\0')
		return ((char *)(s + counter));
	return (NULL);
}
