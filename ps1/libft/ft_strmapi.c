/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:56:09 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/01 16:40:52 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*p;

	len = ft_strlen(s);
	p = malloc(len + 1);
	if (p)
	{
		i = 0;
		while (i < len)
		{
			p[i] = (*f)(i, s[i]);
			i++;
		}
		p[len] = '\0';
	}
	return (p);
}
