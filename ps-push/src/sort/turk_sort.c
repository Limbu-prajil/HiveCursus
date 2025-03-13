#include "../../inc/push_swap.h"

void	sort_three(t_data *stacks)
{
	if (stacks->a->nbr == find_max(stacks->a))
	{
		ra(stacks);
		if (!check_sorted(stacks->a))
			sa(stacks);
	}
	else if (stacks->a->next->nbr == find_max(stacks->a))
	{
		rra(stacks);
		if (!check_sorted(stacks->a))
			sa(stacks);
	}
	else
		sa(stacks);
}

void	sort_until_three(t_data *stacks)
{
	t_list	*sta;

	while (ft_lstsize(stacks->a) > 3)
	{
		sta = stacks->a;
		critical_art_b(stacks, sta, 0, INT_MAX);
		pb(stacks);
	}
}

void	sort_b(t_data *stacks)
{
	if (ft_lstsize(stacks->a) > 3 && !check_sorted(stacks->a))
		pb(stacks);
	if (ft_lstsize(stacks->a) > 3 && !check_sorted(stacks->a))
		pb(stacks);
	if (ft_lstsize(stacks->a) > 3 && !check_sorted(stacks->a))
		sort_until_three(stacks);
	if (!check_sorted(stacks->a))
		sort_three(stacks);
}

void	sort_a(t_data *stacks)
{
	t_list	*stb;

	while (stacks->b)
	{
		stb = stacks->b;
		critical_art_a(stacks, stb, 0, INT_MAX);
		pa(stacks);
	}
}

void	sort(t_data *stacks)
{
	if (ft_lstsize(stacks->a) == 2)
		sa(stacks);
	else if (ft_lstsize(stacks->a) == 3)
		sort_three(stacks);
	else
	{
		sort_b(stacks);
		sort_a(stacks);
		while (!check_sorted(stacks->a))
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
