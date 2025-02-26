/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudloff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:16:20 by mrudloff          #+#    #+#             */
/*   Updated: 2022/10/27 11:44:36 by mrudloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	ft_str_cat(char *join, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1);
	total_len += ft_strlen(s2);
	join = (char *)malloc((total_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_str_cat(join, s1, s2);
	return (join);
}
