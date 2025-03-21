#include "../../inc/push_swap.h"

void	opti_ops_to_stack_a(t_data *stacks, int depth_b, int opsnum)
{
	int		best_nbr_to_push;
	int		best_depth_in_b;
	t_list	*stb;

	stb = stacks->b;
	while (stb->next != stacks->b)
	{
		if (best_opsnum(stacks, best_depth_in_a(stacks->a, stb->nbr), depth_b) < opsnum)
		{
			opsnum = best_opsnum(stacks, best_depth_in_a(stacks->a, stb->nbr), depth_b);
			best_nbr_to_push = stb->nbr;
			best_depth_in_b = depth_b;
		}
		depth_b++;
		stb = stb->next;
	}
	if (best_opsnum(stacks, best_depth_in_a(stacks->a, stb->nbr), depth_b) < opsnum)
	{
		opsnum = best_opsnum(stacks, best_depth_in_a(stacks->a, stb->nbr), depth_b);
		best_nbr_to_push = stb->nbr;
		best_depth_in_b = depth_b;
	}
	best_ops_to_exec(stacks, best_depth_in_a(stacks->a, best_nbr_to_push), best_depth_in_b);
}
