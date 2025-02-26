/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:44:32 by kjullien          #+#    #+#             */
/*   Updated: 2024/11/14 22:25:56 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	counter;
	char	*r;

	len = ft_strlen(s);
	r = malloc((len + 1) * sizeof(char));
	if (!r)
		return (NULL);
	counter = 0;
	while (counter < len)
	{
		r[counter] = f(counter, s[counter]);
		counter++;
	}
	r[counter] = '\0';
	return (r);
}
