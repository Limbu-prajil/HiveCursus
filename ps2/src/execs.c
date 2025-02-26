/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:48:28 by ocassany          #+#    #+#             */
/*   Updated: 2023/08/13 17:02:14 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra_rrb_exec(t_data *stacks, int depth_a, int depth_b)
{
	while (depth_a != ft_lstsize(stacks->a) && depth_b != ft_lstsize(stacks->b))
	{
		rrr(stacks);
		depth_a++;
		depth_b++;
	}
	if (depth_a == ft_lstsize(stacks->a))
	{
		while (depth_b != ft_lstsize(stacks->b))
		{
			rrb(stacks);
			depth_b++;
		}
	}
	else if (depth_b == ft_lstsize(stacks->b))
	{
		while (depth_a != ft_lstsize(stacks->a))
		{
			rra(stacks);
			depth_a++;
		}
	}
}

void	ra_rb_exec(t_data *stacks, int depth_a, int depth_b)
{
	while (depth_a != 0 && depth_b != 0)
	{
		rr(stacks);
		depth_a--;
		depth_b--;
	}
	if (depth_a == 0)
	{
		while (depth_b != 0)
		{
			rb(stacks);
			depth_b--;
		}
	}
	else if (depth_b == 0)
	{
		while (depth_a != 0)
		{
			ra(stacks);
			depth_a--;
		}
	}
}

void	rra_rb_exec(t_data *stacks, int depth_a, int depth_b)
{
	while (depth_b != 0)
	{
		rb(stacks);
		depth_b--;
	}
	while (depth_a != ft_lstsize(stacks->a))
	{
		rra(stacks);
		depth_a++;
	}
}

void	ra_rrb_exec(t_data *stacks, int depth_a, int depth_b)
{
	while (depth_b != ft_lstsize(stacks->b))
	{
		rrb(stacks);
		depth_b++;
	}
	while (depth_a != 0)
	{
		ra(stacks);
		depth_a--;
	}
}

void	combo_exec(t_data *stacks, int depth_a, int depth_b)
{
	if (depth_a > ft_lstsize(stacks->a) / 2 
		&& depth_b > ft_lstsize(stacks->b) / 2)
		rra_rrb_exec(stacks, depth_a, depth_b);
	else if (depth_a <= ft_lstsize(stacks->a) / 2 
		&& depth_b <= ft_lstsize(stacks->b) / 2)
		ra_rb_exec(stacks, depth_a, depth_b);
	else if (depth_a <= ft_lstsize(stacks->a) / 2 
		&& depth_b > ft_lstsize(stacks->b) / 2)
		ra_rrb_exec(stacks, depth_a, depth_b);
	else if (depth_a > ft_lstsize(stacks->a) / 2 
		&& depth_b <= ft_lstsize(stacks->b) / 2)
		rra_rb_exec(stacks, depth_a, depth_b);
}
