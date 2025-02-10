#include "../includes/push_swap.h"
#include "../libft/libft.h"

t_stack *get_node(t_stack *stack, int index)
{
    int i;

    i = 0;
    while (i < index && stack)
    {
        stack = stack->next;
        i++;
    }
    return (stack);
}

t_stack *create_stack(int ac, char **av)
{
    t_stack *stack;
    t_stack *new;
    int     i;

    stack = NULL;
    i = 1;
    while (i < ac)
    {
        new = (t_stack *)malloc(sizeof(t_stack));
        if (!new)
            error_exit(&stack, NULL);
        new->value = ft_atoi(av[i]);
        new->next = stack;
        stack = new;
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
