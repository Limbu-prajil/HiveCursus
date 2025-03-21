/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_ops_to_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:09:23 by plimbu            #+#    #+#             */
/*   Updated: 2025/03/21 15:09:26 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	opti_ops_to_stack_a(t_data *sts, int d_b, int opsnum)
{
	int		b_n_to_p;
	int		b_d_in_b;
	t_list	*stb;

	stb = sts->b;
	while (stb->next != sts->b)
	{
		if (best_opsnum(sts, best_depth_in_a(sts->a, stb->nbr), d_b) < opsnum)
		{
			opsnum = best_opsnum(sts, best_depth_in_a(sts->a, stb->nbr), d_b);
			b_n_to_p = stb->nbr;
			b_d_in_b = d_b;
		}
		d_b++;
		stb = stb->next;
	}
	if (best_opsnum(sts, best_depth_in_a(sts->a, stb->nbr), d_b) < opsnum)
	{
		opsnum = best_opsnum(sts, best_depth_in_a(sts->a, stb->nbr), d_b);
		b_n_to_p = stb->nbr;
		b_d_in_b = d_b;
	}
	best_ops_to_exec(sts, best_depth_in_a(sts->a, b_n_to_p), b_d_in_b);
}
