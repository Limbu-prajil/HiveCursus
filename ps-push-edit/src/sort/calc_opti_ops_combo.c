#include "../../inc/push_swap.h"
/*
int	rra_rrb_calc(t_data *stacks, int best_depth_in_a, int depth_b)
{
	if (ft_lstsize(stacks->a) - best_depth_in_a > ft_lstsize(stacks->b) - depth_b)
		return (ft_lstsize(stacks->a) - best_depth_in_a);
	else
		return (ft_lstsize(stacks->b) - depth_b);
}

int	ra_rb_calc(int best_depth_in_a, int depth_b)
{
	if (best_depth_in_a > depth_b)
		return (best_depth_in_a);
	else
		return (depth_b);
}

int	ra_rrb_calc(t_data *stacks, int best_depth_in_a, int depth_b)
{
	return ((ft_lstsize(stacks->b) - depth_b) + best_depth_in_a);
}

int	rra_rb_calc(t_data *stacks, int best_depth_in_a, int depth_b)
{
	return ((ft_lstsize(stacks->a) - best_depth_in_a) + depth_b);
}
*/
int	best_opsnum(t_data *stacks, int best_depth_in_a, int depth_b)
{
	int sizea;
	int sizeb;

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
