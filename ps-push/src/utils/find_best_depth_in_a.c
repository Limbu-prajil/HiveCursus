/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_depth_in_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:11:12 by plimbu            #+#    #+#             */
/*   Updated: 2025/03/21 15:11:15 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	find_depth(t_list *stack, int nbr)
{
	int		d;

	d = 0;
	while (stack->next != stack)
	{
		if (stack->nbr == nbr)
			return (d);
		d++;
		stack = stack->next;
	}
	return (d);
}

int	best_depth_in_a(t_list *sta, int stbnbr)
{
	int		i;
	t_list	*stanext;

	i = 1;
	if (stbnbr < sta->nbr && stbnbr > sta->prev->nbr)
		i = 0;
	else if (stbnbr > find_max(sta) || stbnbr < find_min(sta))
		i = find_depth(sta, find_min(sta));
	else
	{
		stanext = sta->next;
		while (stbnbr < sta->nbr || stbnbr > stanext->nbr)
		{
			sta = sta->next;
			stanext = stanext->next;
			i++;
		}
	}
	return (i);
}
