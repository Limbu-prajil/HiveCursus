/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:53:34 by ulayus            #+#    #+#             */
/*   Updated: 2023/01/02 19:57:35 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_two(t_list **head_a)
{
	const int	a = (*head_a)->index;
	const int	b = (*head_a)->next->index;

	if (a > b)
		sa(head_a);
}

void	sort_three(t_list **head_a)
{
	const int	a = (*head_a)->index;
	const int	b = (*head_a)->next->index;
	const int	c = (*head_a)->next->next->index;

	if (a < b && b > c && a < c)
	{
		sa(head_a);
		ra(head_a);
	}
	else if (a > b && a < c && b < c)
		sa(head_a);
	else if (a < b && a > c && c < b)
		rra(head_a);
	else if (a > b && b < c && a > c)
		ra(head_a);
	else if (a > b && b > c && a > c)
	{
		sa(head_a);
		rra(head_a);
	}
	else
		return ;
}

void	sort_four(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	tmp = *head_a;
	while (tmp)
	{
		if (tmp->index == 0)
		{
			pb(head_a, head_b);
			break ;
		}
		tmp = tmp->next;
		ra(head_a);
	}
	sort_three(head_a);
	pa(head_a, head_b);
}

void	sort_five(t_list **head_a, t_list **head_b)
{
	while (nb_values(*head_b) != 2)
	{
		if ((*head_a)->index == 0 || (*head_a)->index == 4)
			pb(head_a, head_b);
		rra(head_a);
	}
	sort_three(head_a);
	pa(head_a, head_b);
	if ((*head_a)->index == 4)
	{
		ra(head_a);
		pa(head_a, head_b);
	}
	else
	{
		pa(head_a, head_b);
		ra(head_a);
	}
}
