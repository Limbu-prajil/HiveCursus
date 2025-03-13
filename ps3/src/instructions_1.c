/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:07:31 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/14 14:16:27 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void	sa(t_list **head_a)
{
	int	tmp;

	tmp = (*head_a)->index;
	(*head_a)->index = (*head_a)->next->index;
	(*head_a)->next->index = tmp;
	tmp = (*head_a)->nb;
	(*head_a)->nb = (*head_a)->next->nb;
	(*head_a)->next->nb = tmp;
	ft_printf("sa\n");
}

void	sb(t_list **head_b)
{
	int	tmp;

	tmp = (*head_b)->index;
	(*head_b)->index = (*head_b)->next->index;
	(*head_b)->next->index = tmp;
	tmp = (*head_b)->nb;
	(*head_b)->nb = (*head_b)->next->nb;
	(*head_b)->next->nb = tmp;
	ft_printf("sb\n");
}

void	ss(t_list **head_a, t_list **head_b)
{
	sa(head_a);
	sb(head_b);
}

void	pa(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	if (!*head_b)
		return ;
	tmp = *head_b;
	*head_b = tmp->next;
	if (*head_a)
		tmp->next = *head_a;
	else
		tmp->next = NULL;
	*head_a = tmp;
	ft_printf("pa\n");
}

void	pb(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	if (!*head_a)
		return ;
	tmp = *head_a;
	*head_a = tmp->next;
	if (*head_b)
		tmp->next = *head_b;
	else
		tmp->next = NULL;
	*head_b = tmp;
	ft_printf("pb\n");
}
