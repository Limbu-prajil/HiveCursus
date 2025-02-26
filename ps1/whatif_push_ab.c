/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatif_push_ab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 23:02:51 by pdietric          #+#    #+#             */
/*   Updated: 2024/08/09 09:41:08 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatif_push_ab.h"
#include "get_index_dest.h"

static int	min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

static int	max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

static int	best_motion(int topa, int idxa, int topb, int idxb)
{
	int	mot1;
	int	mot2;
	int	mot3;
	int	mot4;

	mot1 = max(topa - idxa, topb - idxb);
	mot2 = 1 + max(idxa, idxb);
	mot3 = topa - idxa + 1 + idxb;
	mot4 = 1 + idxa + topb - idxb;
	if (min(mot1, mot2) <= min(mot3, mot4))
	{
		if (mot1 <= mot2)
			return (1);
		else
			return (2);
	}
	else
	{
		if (mot3 <= mot4)
			return (3);
		else
			return (4);
	}
}

t_rot	whatif_push_ab(int idxa, t_stack a, t_stack b, char dest)
{
	t_rot	act;
	int		idxb;
	int		best;

	act.common = 0;
	idxb = get_index_dest(b, a.ary[idxa], dest);
	best = best_motion(a.top, idxa, b.top, idxb);
	if (best % 2 == 1)
	{
		act.count_a = a.top - idxa;
		act.count_b = (best == 1) * (b.top - idxb) + (best == 3) * (-1 - idxb);
		act.common = (best == 1) * min(a.top - idxa, b.top - idxb);
	}
	else if (best % 2 == 0)
	{
		act.count_a = -1 - idxa;
		act.count_b = (best == 4) * (b.top - idxb) + (best == 2) * (-1 - idxb);
		act.common = (best == 2) * (-1 - min(idxa, idxb));
	}
	act.count_a -= act.common;
	act.count_b -= act.common;
	return (act);
}
