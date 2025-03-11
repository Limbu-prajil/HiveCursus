/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:08:15 by ocassany          #+#    #+#             */
/*   Updated: 2023/02/10 12:09:41 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tab;
	size_t	len_s;

	len_s = ft_strlen(s);
	tab = (char *)malloc(sizeof(char) * len_s + 1);
	if (!tab)
		return (0);
	ft_memcpy(tab, s, len_s);
	tab[len_s] = '\0';
	return (tab);
}
