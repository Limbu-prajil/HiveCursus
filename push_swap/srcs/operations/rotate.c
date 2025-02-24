#include "push_swap.h"
#include "ft_printf.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		ft_lstadd_back(a, tmp);
		ft_printf("ra\n");
	}
}

void	rb(t_stack **b)
{
	t_stack	*tmp;

	if (*b && (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = NULL;
		ft_lstadd_back(b, tmp);
		ft_printf("rb\n");
	}
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}

/*
void    ra(t_stack **a)
{
    t_stack *tmp;
    t_stack *last;

    if (*a && (*a)->next)
    {
        tmp = *a;
        *a = (*a)->next;
        last = *a;
        while (last->next)
            last = last->next;
        last->next = tmp;
        tmp->next = NULL;
        write(1, "ra\n", 3);
    }
}

void    rb(t_stack **b)
{
    t_stack *tmp;
    t_stack *last;

    if (*b && (*b)->next)
    {
        tmp = *b;
        *b = (*b)->next;
        last = *b;
        while (last->next)
            last = last->next;
        last->next = tmp;
        tmp->next = NULL;
        write(1, "rb\n", 3);
    }
}
*/