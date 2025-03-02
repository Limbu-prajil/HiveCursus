#include "push_swap.h"

int is_sorted(t_stack *stack)
{
    t_stack *start = stack;

    if (!stack || stack->next == stack)
        return 1;

    while (stack->next != start)
    {
        if (stack->value > stack->next->value)
            return 0;
        stack = stack->next;
    }
    return 1;
}

void push_swap(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);

    if (size <= 3)
        sort_three(a);
    else if (size <= 5)
        sort_five(a, b);
    else
        sort_large(a, b, size);
}

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    if (argc < 2)
        return (0);
    a = parse_input(argc, argv);
    //print_stack(a, 'A');
    if (!is_sorted(a))
        push_swap(&a, &b);
    //print_stack(a, 'A');
    free_stack(&a);
    free_stack(&b);
    return (0);
}
