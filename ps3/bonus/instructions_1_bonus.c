/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:07:31 by ulayus            #+#    #+#             */
/*   Updated: 2023/01/07 10:42:59 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_bonus.h"

void	sa(t_list **head_a)
{
	int	tmp;

	tmp = (*head_a)->index;
	(*head_a)->index = (*head_a)->next->index;
	(*head_a)->next->index = tmp;
	tmp = (*head_a)->nb;
	(*head_a)->nb = (*head_a)->next->nb;
	(*head_a)->next->nb = tmp;
}

void	sb(t_list **head_b)
{
	int	tmp;

	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	tmp = (*head_b)->index;
	(*head_b)->index = (*head_b)->next->index;
	(*head_b)->next->index = tmp;
	tmp = (*head_b)->nb;
	(*head_b)->nb = (*head_b)->next->nb;
	(*head_b)->next->nb = tmp;
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
}
