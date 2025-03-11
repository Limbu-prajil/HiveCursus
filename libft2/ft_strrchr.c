/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:17:23 by ocassany          #+#    #+#             */
/*   Updated: 2023/02/05 15:19:42 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*f;
	int		len_s;

	f = (char *)s;
	len_s = ft_strlen(s);
	while (len_s > 0)
	{
		if (f[len_s] == (char)c)
			return (&f[len_s]);
		len_s--;
	}
	if (f[len_s] == (char)c)
		return (&f[len_s]);
	return (NULL);
}
