/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:13:48 by kjullien          #+#    #+#             */
/*   Updated: 2024/11/14 22:24:02 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static char	*ft_handle_big_start(void)
{
	char	*r;

	r = malloc(1 * sizeof(char));
	if (!r)
		return (NULL);
	r[0] = '\0';
	return (r);
}

char		*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	counter;
	char	*r;
	size_t	r_size;

	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_handle_big_start());
	if (s_len - start < len)
		r_size = s_len - start;
	else
		r_size = len;
	r = malloc((r_size + 1) * sizeof(char));
	if (!r)
		return (NULL);
	counter = 0;
	while (counter < r_size)
	{
		*(r + counter) = *(s + start + counter);
		counter++;
	}
	*(r + counter) = '\0';
	return (r);
}
