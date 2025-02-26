/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_limits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:23:48 by ocassany          #+#    #+#             */
/*   Updated: 2023/08/13 17:03:10 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_min(t_list *stack)
{
	t_list	*tmp;
	int		min;

	tmp = stack;
	min = stack->nbr;
	while (tmp->next != stack)
	{
		if (tmp->nbr < min)
			min = tmp->nbr;
		tmp = tmp->next;
	}
	if (tmp->nbr < min)
		min = tmp->nbr;
	return (min);
}

int	find_max(t_list *stack)
{
	t_list	*tmp;
	int		max;

	tmp = stack;
	max = stack->nbr;
	while (tmp->next != stack)
	{
		if (tmp->nbr > max)
			max = tmp->nbr;
		tmp = tmp->next;
	}
	if (tmp->nbr > max)
		max = tmp->nbr;
	return (max);
}
