#include "../../inc/push_swap.h"

int	find_depth(t_list *stack, int nbr)
{
	t_list	*tmp;
	int		d;

	tmp = stack;
	d = 0;
	while (tmp->next != stack)
	{
		if (tmp->nbr == nbr)
			return (d);
		d++;
		tmp = tmp->next;
	}
	return (d);
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
