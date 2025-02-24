#include "push_swap.h"
#include "ft_printf.h"

void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = *a;
		*a = tmp;
		ft_printf("sa\n");
	}
}

void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (*b && (*b)->next)
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = *b;
		*b = tmp;
		ft_printf("sb\n");
	}
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}