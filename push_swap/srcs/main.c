#include "../includes/push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    if (ac < 2)
        return (0);
    if (!is_valid_input(ac, av))
    {
        write(2, "Error\n", 6);
        return (1);
    }
    a = create_stack(ac, av);
    b = NULL;
    
    if (is_sorted(a))
    {
        write(1, "Stack is already sorted.\n", 24);
        free_stack(&a);
        return (0);
    }

    sort_stack(&a, &b);
    
    free_stack(&a);
    free_stack(&b);
    return (0);
}
