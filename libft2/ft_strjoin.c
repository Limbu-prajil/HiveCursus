/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:35:11 by kjullien          #+#    #+#             */
/*   Updated: 2024/11/14 22:28:27 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*r;
	size_t	counter;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	r = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!r)
		return (NULL);
	counter = 0;
	while (counter < s1_len)
	{
		*(r + counter) = *(s1 + counter);
		counter++;
	}
	while (counter < s2_len + s1_len)
	{
		*(r + counter) = *(s2 + counter - s1_len);
		counter++;
	}
	*(r + counter) = '\0';
	return (r);
}
