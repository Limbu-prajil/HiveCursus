#include "push_swap.h"

void exit_error(const char *message)
{
    write(2, "Error\n", 6);
    if (message)
        write(2, message, ft_strlen(message));
    exit(1);
}

size_t ft_strlen(const char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

void free_stack(t_stack **stack)
{
    t_stack *temp;
    t_stack *start;

    if (!stack || !*stack)
        return;
    start = *stack;
    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        if (temp == start)
            break;
        *stack = temp;
    }
    *stack = NULL;
}

void print_stack(t_stack *stack, char name)
{
    t_stack *start = stack;

    if (!stack)
    {
        write(1, "Stack is empty\n", 15);
        return;
    }
    write(1, &name, 1);
    write(1, ": ", 2);
    do {
        char num[12];
        int len = sprintf(num, "%d ", stack->value);
        write(1, num, len);
        stack = stack->next;
    } while (stack != start);
    write(1, "\n", 1);
}
