#include "../../inc/push_swap.h"

int	find_min(t_list *stack)
{
	t_list	*tmp;
	int		min;

	tmp = stack;
	min = stack->nbr;
	while (tmp->next != stack)
	{
		if (tmp->nbr < min)
			min = tmp->nbr;
		tmp = tmp->next;
	}
	if (tmp->nbr < min)
		min = tmp->nbr;
	return (min);
}
