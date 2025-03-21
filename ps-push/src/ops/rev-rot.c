/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev-rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:29:47 by plimbu            #+#    #+#             */
/*   Updated: 2025/03/21 14:29:50 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rra(t_data *stacks)
{
	stacks->a = stacks->a->prev;
	ft_printf("rra\n");
}

void	rrb(t_data *stacks)
{
	stacks->b = stacks->b->prev;
	ft_printf("rrb\n");
}

void	rrr(t_data *stacks)
{
	stacks->a = stacks->a->prev;
	stacks->b = stacks->b->prev;
	ft_printf("rrr\n");
}
