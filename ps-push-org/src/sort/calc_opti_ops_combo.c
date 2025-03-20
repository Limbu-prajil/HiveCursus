#include "../../inc/push_swap.h"
/*
int	rra_rrb_calc(t_data *stacks, int depth_a, int depth_b)
{
	if (ft_lstsize(stacks->a) - depth_a > ft_lstsize(stacks->b) - depth_b)
		return (ft_lstsize(stacks->a) - depth_a);
	else
		return (ft_lstsize(stacks->b) - depth_b);
}

int	ra_rb_calc(int depth_a, int depth_b)
{
	if (depth_a > depth_b)
		return (depth_a);
	else
		return (depth_b);
}

int	rra_rb_calc(t_data *stacks, int depth_a, int depth_b)
{
	return ((ft_lstsize(stacks->a) - depth_a) + depth_b);
}

int	ra_rrb_calc(t_data *stacks, int depth_a, int depth_b)
{
	return ((ft_lstsize(stacks->b) - depth_b) + depth_a);
}
*/
int	best_combo(t_data *stacks, int depth_a, int depth_b)
{
	int sizea;
	int sizeb;

	sizea = ft_lstsize(stacks->a);
	sizeb = ft_lstsize(stacks->b);
	if (depth_a == 0 && depth_b == 0)
		return (0);
	else if (depth_a > (sizea / 2) && depth_b > (sizeb / 2))
	{
		if (sizea - depth_a > sizeb - depth_b)
			return (sizea - depth_a);
		return (sizeb - depth_b);
	}
	else if (depth_a <= (sizea / 2) && depth_b <= (sizeb / 2))
	{
		if (depth_a > depth_b)
			return (depth_a);
		return (depth_b);
	}
	else if (depth_a <= (sizea / 2) && depth_b > (sizeb / 2))
		return ((sizeb - depth_b) + depth_a);
	else if (depth_a > (sizea / 2) && depth_b <= (sizeb / 2))
		return ((sizea - depth_a) + depth_b);
	return (0);
}
