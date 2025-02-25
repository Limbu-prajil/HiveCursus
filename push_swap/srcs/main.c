#include "push_swap.h"

// Function to print the stack vertically
void    print_stack_vertical(t_stack *stack, const char *stack_name)
{
    write(1, stack_name, ft_strlen(stack_name));
    write(1, ":\n", 2);
    while (stack)
    {
        ft_putnbr_fd(stack->value, 1);
        write(1, "\n", 1);
        stack = stack->next;
    }
    write(1, "\n", 1);
}

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
    //write(1, "Before sorting:\n", 16);
    //print_stack_vertical(a, "Stack a");
    if (is_sorted(a))
    {
        write(1, "Stack is already sorted.\n", 24);
        free_stack(&a);
        return (0);
    }
    sort_stack(&a, &b);
    //write(1, "After sorting:\n", 15);
    //print_stack_vertical(a, "Stack a");
    sort_stack(&a, &b);
    free_stack(&a);
    free_stack(&b);
    return (0);
}
