/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:12:26 by plimbu            #+#    #+#             */
/*   Updated: 2025/02/24 16:12:29 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack **from, t_stack **to)
{
	t_stack	*node_to_push;

	if (!from || !(*from))
		return ;
	node_to_push = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	node_to_push->next = *to;
	if (*to)
		(*to)->prev = node_to_push;
	*to = node_to_push;
	node_to_push = NULL;
	//ft_printf("Pushed %d to stack B. ", node_to_push->value);
	free_stack(&node_to_push);
	ft_printf("pb\n");
}

void	push_a(t_stack **from, t_stack **to)
{
	t_stack	*node_to_push;

	if (!from || !(*from))
		return ;
	node_to_push = *from;
	*from = (*from)->next;
	if (*from)
	(*from)->prev = NULL;
	ft_lstadd_front(to, node_to_push);
	node_to_push = NULL;
	//ft_printf("Pushed %d to stack A. ", node_to_push->value);
	free_stack(&node_to_push);
	ft_printf("pa\n");
}
