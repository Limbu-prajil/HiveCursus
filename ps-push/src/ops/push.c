/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:29:22 by plimbu            #+#    #+#             */
/*   Updated: 2025/03/21 14:29:31 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	pa2(t_data *stacks, t_list *tmp)
{
	tmp->prev = ft_lstlast(stacks->a);
	ft_lstlast(stacks->a)->next = tmp;
	tmp->next = stacks->a;
	stacks->a->prev = tmp;
	stacks->a = tmp;
}

void	pa(t_data *stacks)
{
	t_list	*tmp;

	if (!stacks->b)
		return ;
	tmp = stacks->b;
	if (stacks->b->next != stacks->b)
	{
		tmp->prev->next = stacks->b->next;
		tmp->next->prev = stacks->b->prev;
		stacks->b = stacks->b->next;
	}
	else
		stacks->b = NULL;
	if (!stacks->a)
	{
		stacks->a = tmp;
		tmp->prev = tmp;
		tmp->next = tmp;
	}
	else
		pa2(stacks, tmp);
	ft_printf("pa\n");
}

void	pb2(t_data *stacks, t_list *tmp)
{
	tmp->prev = ft_lstlast(stacks->b);
	ft_lstlast(stacks->b)->next = tmp;
	tmp->next = stacks->b;
	stacks->b->prev = tmp;
	stacks->b = tmp;
}

void	pb(t_data *stacks)
{
	t_list	*tmp;

	if (!stacks->a)
		return ;
	tmp = stacks->a;
	if (stacks->a->next != stacks->a)
	{
		tmp->prev->next = stacks->a->next;
		tmp->next->prev = stacks->a->prev;
		stacks->a = stacks->a->next;
	}
	else
		stacks->a = NULL;
	if (!stacks->b)
	{
		stacks->b = tmp;
		tmp->prev = tmp;
		tmp->next = tmp;
	}
	else
		pb2(stacks, tmp);
	ft_printf("pb\n");
}
