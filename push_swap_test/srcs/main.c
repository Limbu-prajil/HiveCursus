#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    if (ac < 2)
        return (0);
    if (not_valid_input(ac, av))
    {
        write(2, "Error\n", 6);
        return (1);
    }
    a = create_stack(ac, av);
    b = NULL;
    
    if (is_sorted(a))
    {
        ft_printf("Stack is already sorted.\n");
        free_stack(&a);
        return (0);
    }
    print_stack(a, "Stack A (Initial)");

    push_swap_sort(&a, &b);
    print_stack(a, "Stack A (Sorted)");

    free_stack(&a);
    free_stack(&b);
    return (0);
}
