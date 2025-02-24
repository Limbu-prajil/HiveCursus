#include "push_swap.h"
#include "ft_printf.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*a && (*a)->next)
	{
		tmp = *a;
		while (tmp->next->next)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = NULL;
		last->next = *a;
		*a = last;
		ft_printf("rra\n");
	}
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*b && (*b)->next)
	{
		tmp = *b;
		while (tmp->next->next)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = NULL;
		last->next = *b;
		*b = last;
		ft_printf("rrb\n");
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}