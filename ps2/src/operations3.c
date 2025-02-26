/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:07:45 by ocassany          #+#    #+#             */
/*   Updated: 2023/08/13 17:14:14 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
