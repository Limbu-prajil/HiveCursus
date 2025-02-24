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

#include <stdio.h>
#include <stdlib.h>

#define WD_NUM 1000
#define WD_LEN 1000

static void free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

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

static char	*skip_spaces(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	return (str);
}

static char	**split(char *str, char **tab, int *j)
{
	int	k;
	
	k = 0;
	str = skip_spaces(str);
	while (*str)
	{
		if (*str > 32)
		{
			k = 0;
			tab[*j] = (char *)malloc(sizeof(char ) * WD_LEN);
			if (!tab[*j])
				return (stop_leak(tab, *j));
			while (*str > 32)
				tab[*j][k++] = *str++;
			tab[*j][k] = '\0';
			(*j)++;
		}
		else
			str++;
	}
	return (tab);
}

char **ft_split(char *str)
{
	int		j;
	char	**tab;

	j = 0;
	tab = (char **)malloc(sizeof(char *) * WD_NUM);
	if (!tab)
		return (NULL);
	tab = split(str, tab, &j);
	tab[j] = 0;
	return (tab);
}

int main(void)
{
    char **result;
    char str[] = "  Hello   world!  This is a test. And its  a   last  one! ";
    int i;

    result = ft_split(str);
    if (!result)
    {
        printf("Memory allocation failed!\n");
        return (1);
    }
    i = 0;
    while (result[i])
    {
        printf("Word %d: %s\n", i + 1, result[i]);
        i++;
    }
    free_tab(result);

    return (0);
}
