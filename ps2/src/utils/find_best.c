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

int	best_depth_a(t_list *sta, int nbrb)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (nbrb < sta->nbr && nbrb > sta->prev->nbr)
		i = 0;
	else if (nbrb > find_max(sta) || nbrb < find_min(sta))
		i = find_depth(sta, find_min(sta));
	else
	{
		tmp = sta->next;
		while (nbrb < sta->nbr || nbrb > tmp->nbr)
		{
			sta = sta->next;
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}

int	best_depth_b(t_list *stb, int nbra)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (nbra > stb->nbr && nbra < stb->prev->nbr)
		i = 0;
	else if (nbra > find_max(stb) || nbra < find_min(stb))
		i = find_depth(stb, find_max(stb));
	else
	{
		tmp = stb->next;
		while (nbra > stb->nbr || nbra < tmp->nbr)
		{
			stb = stb->next;
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}
