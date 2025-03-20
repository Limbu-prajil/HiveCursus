#include "../../inc/push_swap.h"

void	opti_ops_to_stack_a(t_data *stacks, t_list *stb, int depth_b, int ops)
{
	int		best_nbr;
	int		best_depth_b;

	while (stb->next != stacks->b)
	{
		if (best_combo(stacks, best_depth_a(stacks->a, stb->nbr), depth_b) < ops)
		{
			ops = best_combo(stacks, best_depth_a(stacks->a, stb->nbr), depth_b);
			best_nbr = stb->nbr;
			best_depth_b = depth_b;
		}
		depth_b++;
		stb = stb->next;
	}
	if (best_combo(stacks, best_depth_a(stacks->a, stb->nbr), depth_b) < ops)
	{
		ops = best_combo(stacks, best_depth_a(stacks->a, stb->nbr), depth_b);
		best_nbr = stb->nbr;
		best_depth_b = depth_b;
	}
	combo_exec(stacks, best_depth_a(stacks->a, best_nbr), best_depth_b);
}

void	opti_ops_to_stack_b(t_data *stacks, t_list *sta, int depth_a, int ops)
{
	int		best_nbr;
	int		best_depth_a;

	while (sta->next != stacks->a)
	{
		if (best_combo(stacks, depth_a, best_depth_b(stacks->b, sta->nbr)) < ops)
		{
			ops = best_combo(stacks, depth_a, best_depth_b(stacks->b, sta->nbr));
			best_nbr = sta->nbr;
			best_depth_a = depth_a;
		}
		depth_a++;
		sta = sta->next;
	}
	if (best_combo(stacks, depth_a, best_depth_b(stacks->b, sta->nbr)) < ops)
	{
		ops = best_combo(stacks, depth_a, best_depth_b(stacks->b, sta->nbr));
		best_nbr = sta->nbr;
		best_depth_a = depth_a;
	}
	combo_exec(stacks, best_depth_a, best_depth_b(stacks->b, best_nbr));
}
