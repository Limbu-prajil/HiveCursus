/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:23:19 by ulayus            #+#    #+#             */
/*   Updated: 2023/01/06 16:31:42 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

size_t	nb_values(t_list *head)
{
	size_t	len;

	len = 0;
	while (head)
	{
		head = head->next;
		len++;
	}
	return (len);
}

int	*sort_int_tab(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	isempty(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str == NULL)
		return (1);
	while (str[i])
	{
		if (ft_isspace(str[i]))
			count++;
		i++;
	}
	if (count == i || i == 0)
		return (1);
	return (0);
}

void	free_stacks(t_list *head_a, t_list *head_b)
{
	t_list	*tmp;

	while (head_a)
	{
		tmp = head_a;
		head_a = head_a->next;
		free(tmp);
	}
	while (head_b)
	{
		tmp = head_b;
		head_b = head_b->next;
		free(tmp);
	}
}
