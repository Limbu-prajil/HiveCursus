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
