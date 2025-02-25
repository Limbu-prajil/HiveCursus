#include "push_swap.h"

bool is_integer(const char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (false);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

bool is_duplicate(t_stack *stack, int value)
{
    while (stack)
    {
        if (stack->value == value)
            return (true);
        stack = stack->next;
    }
    return (false);
}

bool is_within_int_range(const char *str)
{
    long num;

    num = ft_atol(str);
    if (num < INT_MIN || num > INT_MAX)
        return (false);
    return (true);
}

bool    is_valid_input(int ac, char **av)
{
    int     i;
    int     j;
    char    **split;
    t_stack *stack;

    stack = NULL;
    i = 1;
    while (i < ac)
    {
        split = ft_split(av[i]);
        //split = ft_split_del(av[i], ' ');
        if (!split)
            return (false);
        j = 0;
        while (split[j])
        {
            if (!is_integer(split[j]) || !is_within_int_range(split[j]))
            {
                free_stack(&stack);
                return (false);
            }
            if (is_duplicate(stack, ft_atoi(split[j])))
            {
                free_stack(&stack);
                return (false);
            }
            t_stack *new = (t_stack *)malloc(sizeof(t_stack));
            if (!new)
            {
                free_stack(&stack);
                return (false);
            }
            new->value = ft_atoi(split[j]);
            new->next = stack;
            stack = new;
            j++;
        }
        i++;
    }
    free_stack(&stack);
    return (true);
}
