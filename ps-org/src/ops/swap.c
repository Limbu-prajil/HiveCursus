#include "../../inc/push_swap.h"

void	sa(t_data *stacks)
{
	if (!stacks->a)
		return ;
	stacks->a = stacks->a->next;
	stacks->a->next->prev = stacks->a->prev;
	stacks->a->prev->next = stacks->a->next;
	stacks->a->next = stacks->a->prev;
	stacks->a->prev = stacks->a->prev->prev;
	stacks->a->next->prev = stacks->a;
	stacks->a->prev->next = stacks->a;
	if (stacks->a->next != stacks->a)
		ft_printf("sa\n");
}

void	sb(t_data *stacks)
{
	if (!stacks->b)
		return ;
	stacks->b = stacks->b->next;
	stacks->b->next->prev = stacks->b->prev;
	stacks->b->prev->next = stacks->b->next;
	stacks->b->next = stacks->b->prev;
	stacks->b->prev = stacks->b->prev->prev;
	stacks->b->next->prev = stacks->b;
	stacks->b->prev->next = stacks->b;
	if (stacks->b->next != stacks->b)
		ft_printf("sb\n");
}

void	ss(t_data *stacks)
{
	sa(stacks);
	sb(stacks);
	ft_printf("ss\n");
}
