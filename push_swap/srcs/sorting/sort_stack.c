#include "push_swap.h"

// Sort stack using optimized sorting algorithm
void sort_stack(t_stack **a, t_stack **b)
{
    int size;

    size = stack_size(*a);
    if (size == 2)
        sa(a);
    else if (size == 3)
        sort_three(a);
    else
        sort_algo(a, b);
}