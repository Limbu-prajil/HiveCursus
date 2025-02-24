/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:35:47 by plimbu            #+#    #+#             */
/*   Updated: 2025/02/24 11:35:51 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define WD_NUM 1000
#define WD_LEN 1000

static void	*stop_leak(char **tab, int j)
{
	j = j - 1;
	while (tab[j])
	{
		free(tab[j]);
		j--;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * WD_NUM);
	while (!tab)
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] > 32)
		{
			k = 0;
			tab[j] = (char *)malloc(sizeof(char ) * WD_LEN);
			while (!tab[j])
				return (stop_leak(tab, j));
			while (str[i] > 32)
			{
				tab[j][k] = str[i];
				i++;
				k++;
			}
			tab[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}
