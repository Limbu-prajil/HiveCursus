/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:48:28 by ocassany          #+#    #+#             */
/*   Updated: 2023/08/10 11:19:52 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	rra_rrb_calc(t_data *stacks, int depth_a, int depth_b)
{
	if (ft_lstsize(stacks->a) - depth_a > ft_lstsize(stacks->b) - depth_b)
		return (ft_lstsize(stacks->a) - depth_a);
	else
		return (ft_lstsize(stacks->b) - depth_b);
}

int	ra_rb_calc(int depth_a, int depth_b)
{
	if (depth_a > depth_b)
		return (depth_a);
	else
		return (depth_b);
}

int	rra_rb_calc(t_data *stacks, int depth_a, int depth_b)
{
	return ((ft_lstsize(stacks->a) - depth_a) + depth_b);
}

int	ra_rrb_calc(t_data *stacks, int depth_a, int depth_b)
{
	return ((ft_lstsize(stacks->b) - depth_b) + depth_a);
}
