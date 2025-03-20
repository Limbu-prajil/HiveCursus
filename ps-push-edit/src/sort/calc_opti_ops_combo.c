#include "../../inc/push_swap.h"

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

int	best_combo(t_data *stacks, int depth_a, int depth_b)
{
	if (depth_a == 0 && depth_b == 0)
		return (0);

	else if (depth_a > ft_lstsize(stacks->a) / 2
		&& depth_b > ft_lstsize(stacks->b) / 2)
		return (rra_rrb_calc(stacks, depth_a, depth_b));

	else if (depth_a <= ft_lstsize(stacks->a) / 2
		&& depth_b <= ft_lstsize(stacks->b) / 2)
		return (ra_rb_calc(depth_a, depth_b));

	else if (depth_a <= ft_lstsize(stacks->a) / 2
		&& depth_b > ft_lstsize(stacks->b) / 2)
		return (ra_rrb_calc(stacks, depth_a, depth_b));

	else if (depth_a > ft_lstsize(stacks->a) / 2
		&& depth_b <= ft_lstsize(stacks->b) / 2)
		return (rra_rb_calc(stacks, depth_a, depth_b));

	return (0);
}
