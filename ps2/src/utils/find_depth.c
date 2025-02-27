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
