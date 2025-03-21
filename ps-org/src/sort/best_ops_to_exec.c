#include "../../inc/push_swap.h"

void	rra_rrb_exec(t_data *stacks, int best_depth_in_a, int best_depth_in_b)
{
	while (best_depth_in_a != ft_lstsize(stacks->a) && best_depth_in_b != ft_lstsize(stacks->b))
	{
		rrr(stacks);
		best_depth_in_a++;
		best_depth_in_b++;
	}
	if (best_depth_in_a == ft_lstsize(stacks->a))
	{
		while (best_depth_in_b != ft_lstsize(stacks->b))
		{
			rrb(stacks);
			best_depth_in_b++;
		}
	}
	else if (best_depth_in_b == ft_lstsize(stacks->b))
	{
		while (best_depth_in_a != ft_lstsize(stacks->a))
		{
			rra(stacks);
			best_depth_in_a++;
		}
	}
}

void	ra_rb_exec(t_data *stacks, int best_depth_in_a, int best_depth_in_b)
{
	while (best_depth_in_a != 0 && best_depth_in_b != 0)
	{
		rr(stacks);
		best_depth_in_a--;
		best_depth_in_b--;
	}
	if (best_depth_in_a == 0)
	{
		while (best_depth_in_b != 0)
		{
			rb(stacks);
			best_depth_in_b--;
		}
	}
	else if (best_depth_in_b == 0)
	{
		while (best_depth_in_a != 0)
		{
			ra(stacks);
			best_depth_in_a--;
		}
	}
}

void	ra_rrb_exec(t_data *stacks, int best_depth_in_a, int best_depth_in_b)
{
	while (best_depth_in_b != ft_lstsize(stacks->b))
	{
		rrb(stacks);
		best_depth_in_b++;
	}
	while (best_depth_in_a != 0)
	{
		ra(stacks);
		best_depth_in_a--;
	}
}

void	rra_rb_exec(t_data *stacks, int best_depth_in_a, int best_depth_in_b)
{
	while (best_depth_in_b != 0)
	{
		rb(stacks);
		best_depth_in_b--;
	}
	while (best_depth_in_a != ft_lstsize(stacks->a))
	{
		rra(stacks);
		best_depth_in_a++;
	}
}

void	best_ops_to_exec(t_data *stacks, int best_depth_in_a, int best_depth_in_b)
{
	int sizea;
	int sizeb;

	sizea = ft_lstsize(stacks->a);
	sizeb = ft_lstsize(stacks->b);
	if (best_depth_in_a > sizea / 2 && best_depth_in_b > sizeb / 2)
		rra_rrb_exec(stacks, best_depth_in_a, best_depth_in_b);
	else if (best_depth_in_a <= sizea / 2 && best_depth_in_b <= sizeb / 2)
		ra_rb_exec(stacks, best_depth_in_a, best_depth_in_b);
	else if (best_depth_in_a <= sizea / 2 && best_depth_in_b > sizeb / 2)
		ra_rrb_exec(stacks, best_depth_in_a, best_depth_in_b);
	else if (best_depth_in_a > sizea / 2 && best_depth_in_b <= sizeb / 2)
		rra_rb_exec(stacks, best_depth_in_a, best_depth_in_b);
}
