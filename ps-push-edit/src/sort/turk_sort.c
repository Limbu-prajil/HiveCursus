#include "../../inc/push_swap.h"

void	sort_three(t_data *stacks)
{
	if (stacks->a->nbr == find_max(stacks->a))
	{
		ra(stacks);
		if  (not_sorted(stacks->a))
			sa(stacks);
	}
	else if (stacks->a->next->nbr == find_max(stacks->a))
	{
		rra(stacks);
		if  (not_sorted(stacks->a))
			sa(stacks);
	}
	else
		sa(stacks);
}

void	sort_until_three(t_data *stacks)
{
	while (ft_lstsize(stacks->a) > 3)
	{
		opti_ops_to_stack_b(stacks, 0, INT_MAX);
		pb(stacks);
	}
}

void	sort_stack_b(t_data *stacks)
{
	if (ft_lstsize(stacks->a) > 3 && not_sorted(stacks->a))
		pb(stacks);
	if (ft_lstsize(stacks->a) > 3 && not_sorted(stacks->a))
		pb(stacks);
	if (ft_lstsize(stacks->a) > 3 && not_sorted(stacks->a))
		sort_until_three(stacks);
	while (ft_lstsize(stacks->a) > 3 && not_sorted(stacks->a))
		pb(stacks);
	if  (not_sorted(stacks->a))
		sort_three(stacks);
}

void	sort_stack_a(t_data *stacks)
{
	while (stacks->b)
	{
		opti_ops_to_stack_a(stacks, 0, INT_MAX);
		pa(stacks);
	}
}

void	turk_sort(t_data *stacks)
{
	if (ft_lstsize(stacks->a) == 2)
		sa(stacks);
	else if (ft_lstsize(stacks->a) == 3)
		sort_three(stacks);
	else
	{
		sort_stack_b(stacks);
		sort_stack_a(stacks);
		while  (not_sorted(stacks->a))
		{
			if (find_depth(stacks->a,
					find_min(stacks->a)) > ft_lstsize(stacks->a) / 2)
				rra(stacks);
			else if (find_depth(stacks->a,
					find_min(stacks->a)) <= ft_lstsize(stacks->a) / 2)
				ra(stacks);
		}
	}
}
