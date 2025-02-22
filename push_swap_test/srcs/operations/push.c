#include "push_swap.h"
#include "ft_printf.h"

void push_b(t_stack **from, t_stack **to)
{
    if (!from || !(*from))
        return;
    t_stack *node = *from;
    *from = (*from)->next;
    if (*from)
        (*from)->prev = NULL;
    node->next = *to;
    if (*to)
        (*to)->prev = node;
    *to = node;
    //ft_printf("Pushed %d to stack B.\n", node->value);
    ft_printf("pb\n");
}

void push_a(t_stack **from, t_stack **to)
{
    if (!from || !(*from))
        return;
    t_stack *node = *from;
    *from = (*from)->next;
    if (*from)
        (*from)->prev = NULL;
    node->next = *to;
    if (*to)
        (*to)->prev = node;
    *to = node;
    //ft_printf("Pushed %d to stack A.\n", node->value);
    ft_printf("pa\n");
}