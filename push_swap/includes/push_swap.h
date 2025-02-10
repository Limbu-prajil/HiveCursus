#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
    int             value;
    struct s_stack  *next;
} t_stack;

// Stack operations
void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);

// Stack utils
t_stack *create_stack(int ac, char **av);
t_stack *get_node(t_stack *stack, int index);
void    free_stack(t_stack **stack);
int     stack_size(t_stack *stack);
int     is_sorted(t_stack *stack);

// Sorting
void    sort_stack(t_stack **a, t_stack **b);
void    sort_three(t_stack **a);
void    sort_large(t_stack **a, t_stack **b);

// Timsort utils
void    insertion_sort(t_stack **a, int n);
void    merge(t_stack **a, t_stack **b, int l, int m, int r);
void    timsort(t_stack **a, t_stack **b, int n);

// Error handling
void    error_exit(t_stack **a, t_stack **b);

// Parsing
int     is_valid_input(int ac, char **av);

#endif
