/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:53:57 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/18 09:54:02 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	trim_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_memchr(set, s1[i], ft_strlen(set)) && s1[i])
	{
		i++;
	}
	return (i);
}

static size_t	trim_end(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (ft_memchr(set, s1[i], ft_strlen(set)) && s1[i] >= 0)
	{
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	size_t			end;
	size_t			start;
	size_t			i;

	if (!s1 || !set)
		return (0);
	end = trim_end(s1, set);
	start = trim_start(s1, set);
	if (start == ft_strlen(s1) || !*s1)
		return (ft_strdup(""));
	str = (char *) malloc(sizeof(char) * ((end - start) + 2));
	if (!str)
		return (0);
	i = 0;
	while (start <= end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}
