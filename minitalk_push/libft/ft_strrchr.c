/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:38:25 by kjullien          #+#    #+#             */
/*   Updated: 2024/11/15 00:47:57 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	size_t	counter;
	size_t	len;

	len = ft_strlen(s);
	if (s[len] == '\0' && (unsigned char)c == '\0')
		return ((char *)(s + len));
	counter = 0;
	while ((const char *)&s[(len - 1) - counter] >= s)
	{
		if (s[(len - 1) - counter] == (unsigned char)c)
			return ((char *)(s + ((len - 1) - counter)));
		counter++;
	}
	return (NULL);
}
