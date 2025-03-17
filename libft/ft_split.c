/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:32:28 by ocassany          #+#    #+#             */
/*   Updated: 2023/08/14 18:32:50 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_str(char const *s, char c)
{
	int		i;
	int		nbr;

	nbr = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			nbr++;
		i++;
	}
	return (nbr);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	a;
	size_t	start_index;

	if (!s)
		return (NULL);
	array = ft_calloc(sizeof(char *), (nbr_str(s, c) + 1));
	if (!array)
		return (NULL);
	a = 0;
	i = 0;
	while (i <= ft_strlen(s) && s[i])
	{
		if (s[i] != c)
		{
			start_index = i;
			while (s[i] && s[i] != c)
				i++;
			array[a] = ft_substr(s, start_index, i - start_index);
			a++;
		}
		i++;
	}
	return (array);
}
