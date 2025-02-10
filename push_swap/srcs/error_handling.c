#include "../includes/push_swap.h"

void    error_exit(t_stack **a, t_stack **b)
{
    if (a)
        free_stack(a);
    if (b)
        free_stack(b);
    write(2, "Error\n", 6);
    exit(1);
}
