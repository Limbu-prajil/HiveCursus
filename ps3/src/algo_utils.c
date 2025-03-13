/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:33:10 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/20 16:34:58 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int	check_pos(t_list **head, int index)
{
	t_list	*tmp;
	int		count;

	tmp = *head;
	count = 0;
	while (tmp)
	{
		if (tmp->index == index)
			return (count);
		count++;
		tmp = tmp->next;
	}
	return (0);
}

int	check_pos_range(t_list **head, int max)
{
	t_list	*tmp;
	int		count;

	tmp = *head;
	count = 0;
	while (tmp)
	{
		if (tmp->index <= max)
			return (count);
		count++;
		tmp = tmp->next;
	}
	return (0);
}

void	send_split(int *count, t_mark *marks, t_list **head_a, t_list **head_b)
{
	size_t	len;
	int		pos;

	while (*count < marks->high)
	{
		len = nb_values(*head_a);
		pos = check_pos_range(head_a, marks->low);
		while (*head_a && (*head_a)->index > marks->high)
		{
			if (pos >= (int)len / 2)
				rra(head_a);
			else
				ra(head_a);
		}
		if (*head_a == NULL)
			break ;
		if ((*head_a)->index <= marks->low)
			pb(head_a, head_b);
		else
		{
			pb(head_a, head_b);
			rb(head_b);
		}
		(*count)++;
	}
}
