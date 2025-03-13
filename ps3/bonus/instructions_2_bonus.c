/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:43:21 by ulayus            #+#    #+#             */
/*   Updated: 2023/01/07 10:43:22 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_bonus.h"

void	ra(t_list **head_a)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *head_a;
	next = (*head_a)->next;
	ft_listadd_back(&next, tmp);
	*head_a = next;
}

void	rb(t_list **head_b)
{
	t_list	*tmp;
	t_list	*next;

	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	tmp = *head_b;
	next = (*head_b)->next;
	ft_listadd_back(&next, tmp);
	*head_b = next;
}

void	rr(t_list **head_a, t_list **head_b)
{
	ra(head_a);
	rb(head_b);
}

void	rra(t_list **head_a)
{
	t_list	*lst;
	t_list	*tmp;
	size_t	len;
	size_t	count;

	if (!head_a)
		return ;
	len = nb_values(*head_a);
	tmp = ft_listlast(*head_a);
	ft_listadd_front(head_a, tmp);
	lst = *head_a;
	count = 1;
	while (count < len)
	{
		lst = lst->next;
		count++;
	}
	lst->next = NULL;
}

void	rrb(t_list **head_b)
{
	t_list	*lst;
	t_list	*tmp;
	size_t	len;
	size_t	count;

	if (!head_b)
		return ;
	len = nb_values(*head_b);
	tmp = ft_listlast(*head_b);
	ft_listadd_front(head_b, tmp);
	lst = *head_b;
	count = 1;
	while (count < len)
	{
		lst = lst->next;
		count++;
	}
	lst->next = NULL;
}
