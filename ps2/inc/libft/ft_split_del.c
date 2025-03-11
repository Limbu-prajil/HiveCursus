/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:50:52 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/18 09:50:54 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_count(char *str, char c)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] && str[i] != c)
		{
			i++;
			j++;
		}
		while (str[i] && str[i] != c)
			i++;
	}
	return (j);
}

static void	*stop_leak(char **out_tab, int j)
{
	j = j - 1;
	while (out_tab[j])
	{
		free(out_tab[j]);
		j--;
	}
	free(out_tab);
	return (NULL);
}

static int	word_len(char *str, char c)
{
	int			i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	*allocandfill(char **out_tab, char *src, char c)
{
	int			i;
	int			j;
	int			k;

	j = 0;
	k = 0;
	while (src[k] == c)
		k++;
	while (j < words_count(src, c))
	{
		i = 0;
		out_tab[j] = (char *)malloc(sizeof(char) * (word_len(&src[k], c) + 1));
		if (!out_tab[j])
			return (stop_leak(out_tab, j));
		while (src[k] != c && src[k])
			out_tab[j][i++] = src[k++];
		out_tab[j][i] = '\0';
		while (src[k] == c && src[k])
			k++;
		j++;
	}
	out_tab[j] = NULL;
	return (*out_tab);
}

char	**ft_split_del(char const *s, char c)
{
	int			j;
	char		**tab;
	char		*str;

	j = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	tab = (char **)malloc(sizeof(char *) * (words_count(str, c) + 1));
	if (!tab)
	{
		free(tab);
		return (NULL);
	}
	tab[j] = allocandfill(tab, str, c);
	return (tab);
}
