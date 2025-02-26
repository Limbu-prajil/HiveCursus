/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:07:45 by ocassany          #+#    #+#             */
/*   Updated: 2023/08/08 10:43:08 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
