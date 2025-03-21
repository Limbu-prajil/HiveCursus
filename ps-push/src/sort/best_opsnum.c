/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_opsnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:08:50 by plimbu            #+#    #+#             */
/*   Updated: 2025/03/21 15:08:53 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	best_opsnum(t_data *stacks, int best_depth_in_a, int depth_b)
{
	int	sizea;
	int	sizeb;

	sizea = ft_lstsize(stacks->a);
	sizeb = ft_lstsize(stacks->b);
	if (best_depth_in_a == 0 && depth_b == 0)
		return (0);
	else if (best_depth_in_a > (sizea / 2) && depth_b > (sizeb / 2))
	{
		if (sizea - best_depth_in_a > sizeb - depth_b)
			return (sizea - best_depth_in_a);
		return (sizeb - depth_b);
	}
	else if (best_depth_in_a <= (sizea / 2) && depth_b <= (sizeb / 2))
	{
		if (best_depth_in_a > depth_b)
			return (best_depth_in_a);
		return (depth_b);
	}
	else if (best_depth_in_a <= (sizea / 2) && depth_b > (sizeb / 2))
		return ((sizeb - depth_b) + best_depth_in_a);
	else if (best_depth_in_a > (sizea / 2) && depth_b <= (sizeb / 2))
		return ((sizea - best_depth_in_a) + depth_b);
	return (0);
}
