/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:29:31 by ocassany          #+#    #+#             */
/*   Updated: 2023/02/11 09:50:10 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		bigsize;

	if (!s1 || !s2)
		return (NULL);
	bigsize = ft_strlen(s1) +ft_strlen(s2) + 1;
	tab = malloc(bigsize);
	if (!tab)
		return (NULL);
	ft_memcpy(tab, s1, ft_strlen(s1));
	tab[ft_strlen(s1)] = '\0';
	ft_strlcat(tab, s2, bigsize);
	return (tab);
}
