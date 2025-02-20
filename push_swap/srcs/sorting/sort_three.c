#include "push_swap.h"

void    sort_three(t_stack **a)
{
    if ((*a)->value > (*a)->next->value && (*a)->value > (*a)->next->next->value)
        ra(a);
    else if ((*a)->next->value > (*a)->value && (*a)->next->value > (*a)->next->next->value)
        rra(a);
    if ((*a)->value > (*a)->next->value)
        sa(a);
}