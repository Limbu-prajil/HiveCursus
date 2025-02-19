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
/*
void    insertion_sort(t_stack **a, t_stack **b, int n)
{
    int i;
    t_stack *key;
    t_stack *j;

    i = 1;
    while (i < n)
    {
        key = get_node(*a, i);
        j = get_node(*a, i - 1);
        while (j && j->value > key->value)
        {
            pb(a, b);
            j = get_node(*a, i - 1);
        }
        pa(b, a);
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
            pb(a, b);
            i++;
        }
        else
        {
            pb(a, b);
            j++;
        }
    }
    while (i <= m)
    {
        pb(a, b);
        i++;
    }
    while (j <= r)
    {
        pb(a, b);
        j++;
    }
    while (k <= r)
    {
        pa(b, a);
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
        insertion_sort(a, b, run);
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

// Insertion Sort for small runs
static void insertion_sort(t_stack **a, int len)
{
    t_stack *current;
    t_stack *prev;
    int     i;
    int     j;

    i = 0;
    while (i < len)
    {
        current = *a;
        j = 0;
        while (j < i)
        {
            current = current->next;
            j++;
        }
        prev = current;
        while (prev && prev->next && prev->value > prev->next->value)
        {
            sa(&prev);
            if (prev == *a)
                *a = prev->next;
            prev = prev->next;
        }
        i++;
    }
}

// Merge two sorted runs
static void merge(t_stack **a, t_stack **b, int len_a, int len_b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;
    int     i;
    int     j;

    tmp_a = *a;
    tmp_b = *b;
    i = 0;
    j = 0;
    while (i < len_a && j < len_b)
    {
        if (tmp_a->value <= tmp_b->value)
        {
            ra(&tmp_a);
            i++;
        }
        else
        {
            pb(&tmp_a, &tmp_b);
            j++;
        }
    }
    while (i < len_a)
    {
        ra(&tmp_a);
        i++;
    }
    while (j < len_b)
    {
        pb(&tmp_a, &tmp_b);
        j++;
    }
    while (tmp_b)
    {
        pa(&tmp_a, &tmp_b);
    }
    *a = tmp_a;
}

// Timsort implementation
void timsort(t_stack **a, t_stack **b)
{
    int min_run;
    int len;
    int i;

    len = stack_size(*a);
    min_run = 32; // Minimum run size for Timsort
    i = 0;
    while (i < len)
    {
        insertion_sort(a, min_run);
        i += min_run;
    }
    i = min_run;
    while (i < len)
    {
        merge(a, b, i, i);
        i *= 2;
    }
}

// Sort stack using Timsort
void sort_stack(t_stack **a, t_stack **b)
{
    int size;

    size = stack_size(*a);
    if (size == 2)
        sa(a);
    else if (size == 3)
        sort_three(a);
    else
        timsort(a, b);
}
*/

// Insertion Sort for small runs
void insertion_sort(t_stack **a, int len)
{
    t_stack *current;
    t_stack *prev;
    int     i;

    i = 0;
    while (i < len)
    {
        current = *a;
        prev = NULL;
        while (current && current->next)
        {
            if (current->value > current->next->value)
            {
                sa(a);
                if (prev)
                    prev->next = *a;
                current = *a;
            }
            prev = current;
            current = current->next;
        }
        i++;
    }
}

// Merge two sorted runs
void merge(t_stack **a, t_stack **b, int len_a, int len_b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;
    int     i;
    int     j;

    tmp_a = *a;
    tmp_b = *b;
    i = 0;
    j = 0;
    while (i < len_a && j < len_b)
    {
        if (tmp_a->value <= tmp_b->value)
        {
            ra(&tmp_a);
            i++;
        }
        else
        {
            pb(&tmp_a, &tmp_b);
            j++;
        }
    }
    while (i < len_a)
    {
        ra(&tmp_a);
        i++;
    }
    while (j < len_b)
    {
        pb(&tmp_a, &tmp_b);
        j++;
    }
    while (tmp_b)
    {
        pa(&tmp_a, &tmp_b);
    }
    *a = tmp_a;
}

// Timsort implementation
void timsort(t_stack **a, t_stack **b)
{
    int min_run;
    int len;
    int i;

    len = stack_size(*a);
    min_run = 32; // Minimum run size for Timsort
    i = 0;
    while (i < len)
    {
        insertion_sort(a, min_run);
        i += min_run;
    }
    i = min_run;
    while (i < len)
    {
        merge(a, b, i, i);
        i *= 2;
    }
}

// Sort stack using Timsort
void sort_stack(t_stack **a, t_stack **b)
{
    int size;

    size = stack_size(*a);
    if (size == 2)
        sa(a);
    else if (size == 3)
        sort_three(a);
    else
        timsort(a, b);
}