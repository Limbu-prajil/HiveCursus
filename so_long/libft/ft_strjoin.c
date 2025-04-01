/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 04:12:45 by ashobajo          #+#    #+#             */
/*   Updated: 2024/05/24 17:47:17 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat_str;
	char	*cat_str_start;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	cat_str = (char *) malloc (sizeof(char) * (s1_len + s2_len + 1));
	if (!cat_str)
		return (NULL);
	cat_str_start = cat_str;
	while (*s1)
		*cat_str++ = *s1++;
	while (*s2)
		*cat_str++ = *s2++;
	*cat_str = '\0';
	return (cat_str_start);
}
