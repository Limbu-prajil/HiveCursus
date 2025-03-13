/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:19:00 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/28 13:38:06 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	*create_index(t_list **head_a)
{
	t_list	*tmp;
	int		*tab;
	int		len;
	int		i;

	tmp = *head_a;
	len = nb_values(*head_a);
	tab = ft_calloc(sizeof(int), len);
	if (!tab)
		return (NULL);
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->nb;
		i++;
		tmp = tmp->next;
	}
	tab = sort_int_tab(tab, len);
	return (tab);
}

void	add_index(t_list **head_a)
{
	t_list	*tmp;
	int		*tab;
	int		len;
	int		i;

	tab = create_index(head_a);
	len = nb_values(*head_a);
	i = 0;
	while (i < len)
	{
		tmp = *head_a;
		while (tmp)
		{
			if (tab[i] == tmp->nb)
				tmp->index = i;
			tmp = tmp->next;
		}
		i++;
	}
	free(tab);
}
