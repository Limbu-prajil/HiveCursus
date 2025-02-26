/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:10:08 by ocassany          #+#    #+#             */
/*   Updated: 2023/08/13 16:39:53 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	critical_art_b(t_data *stacks, t_list *tmp, int da, int ops)
{
	int		best_nbr;
	int		best_depth_a;

	best_nbr = -42;
	best_depth_a = -42;
	while (tmp->next != stacks->a)
	{
		if (best_combo(stacks, da, best_depth_b(stacks->b, tmp->nbr)) < ops)
		{
			ops = best_combo(stacks, da, best_depth_b(stacks->b, tmp->nbr));
			best_nbr = tmp->nbr;
			best_depth_a = da;
		}
		da++;
		tmp = tmp->next;
	}
	if (best_combo(stacks, da, best_depth_b(stacks->b, tmp->nbr)) < ops)
	{
		ops = best_combo(stacks, da, best_depth_b(stacks->b, tmp->nbr));
		best_nbr = tmp->nbr;
		best_depth_a = da;
	}
	combo_exec(stacks, best_depth_a, best_depth_b(stacks->b, best_nbr));
}

void	sort_until_three(t_data *stacks)
{
	t_list	*tmp;

	while (ft_lstsize(stacks->a) > 3)
	{
		tmp = stacks->a;
		critical_art_b(stacks, tmp, 0, INT_MAX);
		pb(stacks);
	}
}

void	critical_art_a(t_data *stacks, t_list *tmp, int db, int ops)
{
	int		best_nbr;
	int		best_depth_b;

	best_nbr = -42;
	best_depth_b = -42;
	while (tmp->next != stacks->b)
	{
		if (best_combo(stacks, best_depth_a(stacks->a, tmp->nbr), db) < ops)
		{
			ops = best_combo(stacks, best_depth_a(stacks->a, tmp->nbr), db);
			best_nbr = tmp->nbr;
			best_depth_b = db;
		}
		db++;
		tmp = tmp->next;
	}
	if (best_combo(stacks, best_depth_a(stacks->a, tmp->nbr), db) < ops)
	{
		ops = best_combo(stacks, best_depth_a(stacks->a, tmp->nbr), db);
		best_nbr = tmp->nbr;
		best_depth_b = db;
	}
	combo_exec(stacks, best_depth_a(stacks->a, best_nbr), best_depth_b);
}

void	sort_a(t_data *stacks)
{
	t_list	*tmp;

	while (stacks->b)
	{
		tmp = stacks->b;
		critical_art_a(stacks, tmp, 0, INT_MAX);
		pa(stacks);
	}
}
