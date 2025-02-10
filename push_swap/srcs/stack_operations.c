#include "../includes/push_swap.h"

void    sa(t_stack **a)
{
    t_stack *tmp;

    if (*a && (*a)->next)
    {
        tmp = (*a)->next;
        (*a)->next = tmp->next;
        tmp->next = *a;
        *a = tmp;
        write(1, "sa\n", 3);
    }
}

void    sb(t_stack **b)
{
    t_stack *tmp;

    if (*b && (*b)->next)
    {
        tmp = (*b)->next;
        (*b)->next = tmp->next;
        tmp->next = *b;
        *b = tmp;
        write(1, "sb\n", 3);
    }
}

void    ss(t_stack **a, t_stack **b)
{
    sa(a);
    sb(b);
    write(1, "ss\n", 3);
}

void    pa(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (*b)
    {
        tmp = *b;
        *b = (*b)->next;
        tmp->next = *a;
        *a = tmp;
        write(1, "pa\n", 3);
    }
}

void    pb(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (*a)
    {
        tmp = *a;
        *a = (*a)->next;
        tmp->next = *b;
        *b = tmp;
        write(1, "pb\n", 3);
    }
}

void    ra(t_stack **a)
{
    t_stack *tmp;
    t_stack *last;

    if (*a && (*a)->next)
    {
        tmp = *a;
        *a = (*a)->next;
        last = *a;
        while (last->next)
            last = last->next;
        last->next = tmp;
        tmp->next = NULL;
        write(1, "ra\n", 3);
    }
}

void    rb(t_stack **b)
{
    t_stack *tmp;
    t_stack *last;

    if (*b && (*b)->next)
    {
        tmp = *b;
        *b = (*b)->next;
        last = *b;
        while (last->next)
            last = last->next;
        last->next = tmp;
        tmp->next = NULL;
        write(1, "rb\n", 3);
    }
}

void    rr(t_stack **a, t_stack **b)
{
    ra(a);
    rb(b);
    write(1, "rr\n", 3);
}

void    rra(t_stack **a)
{
    t_stack *tmp;
    t_stack *last;

    if (*a && (*a)->next)
    {
        last = *a;
        while (last->next->next)
            last = last->next;
        tmp = last->next;
        last->next = NULL;
        tmp->next = *a;
        *a = tmp;
        write(1, "rra\n", 4);
    }
}

void    rrb(t_stack **b)
{
    t_stack *tmp;
    t_stack *last;

    if (*b && (*b)->next)
    {
        last = *b;
        while (last->next->next)
            last = last->next;
        tmp = last->next;
        last->next = NULL;
        tmp->next = *b;
        *b = tmp;
        write(1, "rrb\n", 4);
    }
}

void    rrr(t_stack **a, t_stack **b)
{
    rra(a);
    rrb(b);
    write(1, "rrr\n", 4);
}
