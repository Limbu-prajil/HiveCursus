/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:29:58 by plimbu            #+#    #+#             */
/*   Updated: 2025/03/21 14:30:01 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ra(t_data *stacks)
{
	stacks->a = stacks->a->next;
	ft_printf("ra\n");
}

void	rb(t_data *stacks)
{
	stacks->b = stacks->b->next;
	ft_printf("rb\n");
}

void	rr(t_data *stacks)
{
	stacks->a = stacks->a->next;
	stacks->b = stacks->b->next;
	ft_printf("rr\n");
}
