#include "../../inc/push_swap.h"

int	find_depth(t_list *stack, int nbr)
{
	int		d;

	d = 0;
	while (stack->next != stack)
	{
		if (stack->nbr == nbr)
			return (d);
		d++;
		stack = stack->next;
	}
	return (d);
}

int	best_depth_a(t_list *sta, int stbnbr)
{
	int		i;
	t_list	*stack;

	i = 1;
	if (stbnbr < sta->nbr && stbnbr > sta->prev->nbr)
		i = 0;
	else if (stbnbr > find_max(sta) || stbnbr < find_min(sta))
		i = find_depth(sta, find_min(sta));
	else
	{
		stack = sta->next;
		while (stbnbr < sta->nbr || stbnbr > stack->nbr)
		{
			sta = sta->next;
			stack = stack->next;
			i++;
		}
	}
	return (i);
}

int	best_depth_b(t_list *stb, int stanbr)
{
	int		i;
	t_list	*stack;

	i = 1;
	if (stanbr > stb->nbr && stanbr < stb->prev->nbr)
		i = 0;
	else if (stanbr > find_max(stb) || stanbr < find_min(stb))
		i = find_depth(stb, find_max(stb));
	else
	{
		stack = stb->next;
		while (stanbr > stb->nbr || stanbr < stack->nbr)
		{
			stb = stb->next;
			stack = stack->next;
			i++;
		}
	}
	return (i);
}
