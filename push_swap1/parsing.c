#include "push_swap.h"

long safe_atoi(const char *str)
{
    long num = 0;
    int sign = 1;

    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    if (!*str)
        exit_error("Invalid number");
    while (*str)
    {
        if (*str < '0' || *str > '9')
            exit_error("Invalid character");
        num = num * 10 + (*str - '0');
        if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
            exit_error("Number out of range");
        str++;
    }
    return (num * sign);
}

void add_to_stack(t_stack **stack, int value)
{
    t_stack *new = malloc(sizeof(t_stack));
    t_stack *last;

    if (!new)
        exit_error("Memory allocation failed");
    new->value = value;
    if (!*stack)
    {
        new->next = new;
        new->prev = new;
        *stack = new;
    }
    else
    {
        last = (*stack)->prev;
        new->next = *stack;
        new->prev = last;
        last->next = new;
        (*stack)->prev = new;
    }
}

int has_duplicate(t_stack *stack, int num)
{
    t_stack *start = stack;
    if (!stack) return 0;

    do {
        if (stack->value == num)
            return (1);
        stack = stack->next;
    } while (stack != start);
    return (0);
}

t_stack *parse_input(int argc, char **argv)
{
    t_stack *stack = NULL;
    int i = 1;
    long num;

    while (i < argc)
    {
        num = safe_atoi(argv[i]);
        if (has_duplicate(stack, num))
            exit_error("Duplicate number found");
        add_to_stack(&stack, num);
        i++;
    }
    return (stack);
}
