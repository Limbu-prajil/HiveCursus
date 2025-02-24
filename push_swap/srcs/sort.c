#include "../includes/push_swap.h"

void    sort_three(t_stack **a)
{
    if ((*a)->value > (*a)->next->value && (*a)->value > (*a)->next->next->value)
        ra(a);
    else if ((*a)->next->value > (*a)->value && (*a)->next->value > (*a)->next->next->value)
        rra(a);
    if ((*a)->value > (*a)->next->value)
        sa(a);
}

void    insertion_sort(t_stack **a, int n)
{
    t_stack *key;
    t_stack *j;
    int     i;

    i = 1;
    while (i < n)
    {
        key = get_node(*a, i);
        j = get_node(*a, i - 1);
        while (j && j->value > key->value)
        {
            pb(a, &j);
            j = get_node(*a, i - 1);
        }
        pa(&j, a);
        i++;
    }
}

void    merge(t_stack **a, t_stack **b, int l, int m, int r)
{
    int i;
    int j;
    int k;
    t_stack *node_i;
    t_stack *node_j;

    i = l;
    j = m + 1;
    k = l;
    while (i <= m && j <= r)
    {
        node_i = get_node(*a, i);
        node_j = get_node(*a, j);
        if (node_i->value <= node_j->value)
        {
            pb(b, &node_i);
            i++;
        }
        else
        {
            pb(b, &node_j);
            j++;
        }
    }
    while (i <= m)
    {
        node_i = get_node(*a, i);
        pb(b, &node_i);
        i++;
    }
    while (j <= r)
    {
        node_j = get_node(*a, j);
        pb(b, &node_j);
        j++;
    }
    while (k <= r)
    {
        node_i = get_node(*b, k);
        pa(a, &node_i);
        k++;
    }
}

void    timsort(t_stack **a, t_stack **b, int n)
{
    int run;
    int l;
    int m;
    int r;

    run = 32;
    l = 0;
    while (l < n)
    {
        insertion_sort(a, run);
        l += run;
    }
    while (run < n)
    {
        l = 0;
        while (l < n)
        {
            m = l + run - 1;
            r = (l + 2 * run - 1 < n - 1) ? l + 2 * run - 1 : n - 1;
            merge(a, b, l, m, r);
            l += 2 * run;
        }
        run *= 2;
    }
}

void    sort_stack(t_stack **a, t_stack **b)
{
    int size;

    size = stack_size(*a);
    if (size == 2)
        sa(a);
    else if (size == 3)
        sort_three(a);
    else
        timsort(a, b, size);
}
