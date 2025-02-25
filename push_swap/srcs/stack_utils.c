#include "push_swap.h"

t_stack *create_stack(int ac, char **av)
{
    t_stack *stack;
    t_stack *new_node;
    int     i;
    int     j;
    char    **split;

    stack = NULL;
    i = 1;
    while (i < ac)
    {
        split = ft_split(av[i]);
        if (!split)
            error_exit(&stack, NULL);
        j = 0;
        while (split[j])
        {
            new_node = ft_lstnew(ft_atoi(split[j]));
            if (!new_node)
                error_exit(&stack, NULL);
            ft_lstadd_back(&stack, new_node);
            j++;
        }
        i++;
    }
    return (stack);
}

void    free_stack(t_stack **stack)
{
    t_stack *tmp;

    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

int     stack_size(t_stack *stack)
{
    int size;

    size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}

int     is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}
