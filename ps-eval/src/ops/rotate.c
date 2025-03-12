#include "../../inc/push_swap.h"

void	ra(t_data *stacks)
{
	stacks->a = stacks->a->next;
	ft_printf("ra\n");
}

void	rb(t_data *stacks)
{
	stacks->b = stacks->b->next;
	ft_printf("rb\n");
}

void	rr(t_data *stacks)
{
	stacks->a = stacks->a->next;
	stacks->b = stacks->b->next;
	ft_printf("rr\n");
}
