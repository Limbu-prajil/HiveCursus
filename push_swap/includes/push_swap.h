#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
    int             value;
    struct s_stack  *next;
} t_stack;

// stack_operations.c
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

// stack_utils.c
t_stack *get_node(t_stack *stack, int index);
t_stack *create_stack(int ac, char **av);
void    free_stack(t_stack **stack);
int     stack_size(t_stack *stack);
int     is_sorted(t_stack *stack);

// sort.c
void    sort_three(t_stack **a);
void    insertion_sort(t_stack **a, int n);
void    merge(t_stack **a, t_stack **b, int l, int m, int r);
void    timsort(t_stack **a, t_stack **b, int n);
void    sort_stack(t_stack **a, t_stack **b);


// error_handling.c
void    error_exit(t_stack **a, t_stack **b);

// parsing.c
bool is_integer(const char *str);
bool is_duplicate(t_stack *stack, int value);
bool is_within_int_range(const char *str);
bool     is_valid_input(int ac, char **av);

// main.c
void    print_stack_vertical(t_stack *stack, const char *stack_name);


#endif
