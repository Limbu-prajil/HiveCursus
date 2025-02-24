#include "push_swap.h"

void push_b(t_stack **from, t_stack **to)
{
    t_stack *node_to_push;

    if (!from || !(*from))
        return;
    node_to_push = *from;
    *from = (*from)->next;
    if (*from)
        (*from)->prev = NULL;
    /*
    node->next = *to;
    if (*to)
        (*to)->prev = node;
    *to = node;
    */
    ft_lstadd_front(to, node_to_push);
    ft_printf("Pushed %d to stack B. ", node_to_push->value);
    ft_printf("pb\n");
}

void push_a(t_stack **from, t_stack **to)
{
    t_stack *node_to_push;

    if (!from || !(*from))
        return;
    node_to_push = *from;
    *from = (*from)->next;
    if (*from)
        (*from)->prev = NULL;
    /*
    node->next = *to;
    if (*to)
        (*to)->prev = node;
    *to = node;
    */
    ft_lstadd_front(to, node_to_push);
    ft_printf("Pushed %d to stack A. ", node_to_push->value);
    ft_printf("pa\n");
}