#include "../../inc/push_swap.h"

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

int	best_depth_a(t_list *st, int nbr)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (nbr < st->nbr && nbr > st->prev->nbr)
		i = 0;
	else if (nbr > find_max(st) || nbr < find_min(st))
		i = find_depth(st, find_min(st));
	else
	{
		tmp = st->next;
		while (nbr < st->nbr || nbr > tmp->nbr)
		{
			st = st->next;
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}

int	best_depth_b(t_list *st, int nbr)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (nbr > st->nbr && nbr < st->prev->nbr)
		i = 0;
	else if (nbr > find_max(st) || nbr < find_min(st))
		i = find_depth(st, find_max(st));
	else
	{
		tmp = st->next;
		while (nbr > st->nbr || nbr < tmp->nbr)
		{
			st = st->next;
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}
