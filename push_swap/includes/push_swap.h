#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"

// operations
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

// sorting
void    sort_stack(t_stack **a, t_stack **b);
void    sort_three(t_stack **a);
void    sort_algo(t_stack **a, t_stack **b);
int get_chunk_size(int size);
int *copy_stack_to_array(t_stack *a, int size);
void    swap(int *a, int *b);
void    quick_sort(int *arr, int low, int high);
int *find_pivots(t_stack *a, int size, int chunk_size);
void    push_chunks_to_b(t_stack **a, t_stack **b, int *pivots, int size, int chunk_size);
int find_max(t_stack *b);
int find_position(t_stack *b, int target);
void    merge_sorted_to_a(t_stack **a, t_stack **b);

// error
void    error_exit(t_stack **a, t_stack **b);

// parsing
bool    is_integer(const char *str);
bool    is_duplicate(t_stack *stack, int value);
bool    is_within_int_range(const char *str);
bool    is_valid_input(int ac, char **av);

// stack_utils
t_stack *create_stack(int ac, char **av);
void    free_stack(t_stack **stack);
int     stack_size(t_stack *stack);
int     is_sorted(t_stack *stack);

#endif