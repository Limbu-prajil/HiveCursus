/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:23:57 by ocassany          #+#    #+#             */
/*   Updated: 2023/02/05 15:09:31 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*f;

	f = (char *)s;
	i = 0;
	while (f[i])
	{
		if (f[i] == (char)c)
			return (&f[i]);
		i++;
	}
	if (f[i] == (char)c)
		return (&f[i]);
	return (NULL);
}
