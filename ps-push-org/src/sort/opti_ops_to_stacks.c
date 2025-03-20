#include "../../inc/push_swap.h"

void	opti_ops_to_stack_a(t_data *stacks, int depth_b, int opsnum)
{
	int		best_nbr_to_push;
	int		best_depth_in_b;
	t_list	*stb;

	stb = stacks->b;
	while (stb->next != stacks->b)
	{
		if (best_combo(stacks, best_depth_in_a(stacks->a, stb->nbr), depth_b) < opsnum)
		{
			opsnum = best_combo(stacks, best_depth_in_a(stacks->a, stb->nbr), depth_b);
			best_nbr_to_push = stb->nbr;
			best_depth_in_b = depth_b;
		}
		depth_b++;
		stb = stb->next;
	}
	if (best_combo(stacks, best_depth_in_a(stacks->a, stb->nbr), depth_b) < opsnum)
	{
		opsnum = best_combo(stacks, best_depth_in_a(stacks->a, stb->nbr), depth_b);
		best_nbr_to_push = stb->nbr;
		best_depth_in_b = depth_b;
	}
	combo_exec(stacks, best_depth_in_a(stacks->a, best_nbr_to_push), best_depth_in_b);
}

void	opti_ops_to_stack_b(t_data *stacks, int depth_a, int opsnum)
{
	int		best_nbr_to_push;
	int		best_depth_in_a;
	t_list	*sta;

	sta = stacks->a;
	while (sta->next != stacks->a)
	{
		if (best_combo(stacks, depth_a, best_depth_in_b(stacks->b, sta->nbr)) < opsnum)
		{
			opsnum = best_combo(stacks, depth_a, best_depth_in_b(stacks->b, sta->nbr));
			best_nbr_to_push = sta->nbr;
			best_depth_in_a = depth_a;
		}
		depth_a++;
		sta = sta->next;
	}
	if (best_combo(stacks, depth_a, best_depth_in_b(stacks->b, sta->nbr)) < opsnum)
	{
		opsnum = best_combo(stacks, depth_a, best_depth_in_b(stacks->b, sta->nbr));
		best_nbr_to_push = sta->nbr;
		best_depth_in_a = depth_a;
	}
	combo_exec(stacks, best_depth_in_a, best_depth_in_b(stacks->b, best_nbr_to_push));
}
