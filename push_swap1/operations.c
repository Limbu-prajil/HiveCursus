#include "push_swap.h"

void print_operation(const char *op)
{
    while (*op)
        write(1, op++, 1);
    write(1, "\n", 1);
}

void swap(t_stack **stack, char stack_name)
{
    if (!stack || !(*stack) || (*stack)->next == *stack)
        return;
    int temp = (*stack)->value;
    (*stack)->value = (*stack)->next->value;
    (*stack)->next->value = temp;
    print_operation(stack_name == 'a' ? "sa" : "sb");
}

void push(t_stack **src, t_stack **dst, char stack_name)
{
    if (!src || !(*src))
        return;
    t_stack *node = *src;

    if (node->next == node)
        *src = NULL;
    else
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        *src = node->next;
    }

    // Instead of `add_to_stack()`, directly push to the front
    if (!*dst)
    {
        node->next = node;
        node->prev = node;
        *dst = node;
    }
    else
    {
        node->next = *dst;
        node->prev = (*dst)->prev;
        (*dst)->prev->next = node;
        (*dst)->prev = node;
        *dst = node;  // Make the pushed node the new top
    }

    print_operation(stack_name == 'a' ? "pa" : "pb");
}


void rotate(t_stack **stack, char stack_name)
{
    if (!stack || !(*stack) || (*stack)->next == *stack)
        return;

    *stack = (*stack)->next;
    if (stack_name)
        printf("r%c\n", stack_name);
}

void reverse_rotate(t_stack **stack, char stack_name)
{
    if (!stack || !(*stack) || (*stack)->next == *stack)
        return;

    *stack = (*stack)->prev;
    if (stack_name)
        printf("rr%c\n", stack_name);
}
