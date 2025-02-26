/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:10:08 by ocassany          #+#    #+#             */
/*   Updated: 2023/08/13 16:42:54 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_b(t_data *stacks)
{
	if (ft_lstsize(stacks->a) > 3 && !check_sorted(stacks->a))
		pb(stacks);
	if (ft_lstsize(stacks->a) > 3 && !check_sorted(stacks->a))
		pb(stacks);
	if (ft_lstsize(stacks->a) > 3 && !check_sorted(stacks->a))
		sort_until_three(stacks);
	if (!check_sorted(stacks->a))
		sort_three(stacks);
}

void	sort_three(t_data *stacks)
{
	if (stacks->a->nbr == find_max(stacks->a))
	{
		ra(stacks);
		if (!check_sorted(stacks->a))
			sa(stacks);
	}
	else if (stacks->a->next->nbr == find_max(stacks->a))
	{
		rra(stacks);
		if (!check_sorted(stacks->a))
			sa(stacks);
	}
	else
		sa(stacks);
}

void	sort(t_data *stacks)
{
	if (ft_lstsize(stacks->a) == 2)
		sa(stacks);
	else if (ft_lstsize(stacks->a) == 3)
		sort_three(stacks);
	else
	{
		sort_b(stacks);
		sort_a(stacks);
		while (!check_sorted(stacks->a))
		{
			if (find_depth(stacks->a,
					find_min(stacks->a)) > ft_lstsize(stacks->a) / 2)
				rra(stacks);
			else if (find_depth(stacks->a,
					find_min(stacks->a)) <= ft_lstsize(stacks->a) / 2)
				ra(stacks);
		}
	}
}
