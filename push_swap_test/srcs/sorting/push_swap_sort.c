#include "push_swap.h"

t_stack *find_min(t_stack *a)
{
    t_stack *min_node = a;
    while (a)
    {
        if (a->value < min_node->value)
            min_node = a;
        a = a->next;
    }
    return min_node;
}

void move_to_top(t_stack **a, t_stack *min_node)
{
    if (!a || !(*a) || !min_node || *a == min_node)
        return;

    // Loop if min_node is not head/first/top node
    while (*a != min_node)
    {
        if (min_node->prev == NULL)
            break;

        // Detach min_node from its current position
        if (min_node->prev)
            min_node->prev->next = min_node->next;
        if (min_node->next)
            min_node->next->prev = min_node->prev;

        // Move min_node to the top
        min_node->next = *a;
        (*a)->prev = min_node;
        min_node->prev = NULL;
        *a = min_node;
    }
}

void push_swap_sort(t_stack **a, t_stack **b)
{
    while (*a)
    {
        t_stack *min_node = find_min(*a);
        ft_printf("Found min: %d\n", min_node->value);
        move_to_top(a, min_node);
        print_stack(*a, "Stack A before push");
        push_b(a, b);
        print_stack(*a, "Stack A after push");
        print_stack(*b, "Stack B after push");
        ft_printf("--------------------------\n");
    }
    while (*b) {
        push_a(b, a);
    }
}