/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:12:56 by plimbu            #+#    #+#             */
/*   Updated: 2025/02/24 16:12:59 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack *a)
{
	t_stack	*min_node;

	min_node = a;
	while (a)
	{
		if (a->value < min_node->value)
			min_node = a;
		a = a->next;
	}
	return (min_node);
}

void	move_to_top(t_stack **a, t_stack *min_node)
{
	if (!a || !(*a) || !min_node || *a == min_node)
		return ;
	while (*a != min_node)
	{
		if (min_node->prev == NULL)
			break ;
		if (min_node->prev)
			min_node->prev->next = min_node->next;
		if (min_node->next)
			min_node->next->prev = min_node->prev;
		min_node->next = *a;
		(*a)->prev = min_node;
		min_node->prev = NULL;
		*a = min_node;
	}
	//ft_printf("Moved %d to the top\n", min_node->value);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*min_node;

	while (*a)
	{
		min_node = find_min(*a);
		//ft_printf("Found min: %d.\n", min_node->value);
		move_to_top(a, min_node);
		//print_stack(*a, "Stack A before push");
		push_b(a, b);
		//print_stack(*a, "Stack A after push");
		//print_stack(*b, "Stack B after push");
		//ft_printf("-----------------------------------\n");
	}
	while (*b)
	{
		push_a(b, a);
	}
}
