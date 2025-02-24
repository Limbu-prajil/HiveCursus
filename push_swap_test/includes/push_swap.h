#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"
# include "ft_printf.h"

// operations
void push_b(t_stack **from, t_stack **to);
void push_a(t_stack **from, t_stack **to);

// sorting
void push_swap_sort(t_stack **a, t_stack **b);
t_stack *find_min(t_stack *a);
void move_to_top(t_stack **a, t_stack *min_node);

// parsing
bool     is_sorted(t_stack *stack);
bool    not_integer(const char *str);
bool    is_duplicate(t_stack *stack, int value);
bool    not_within_int_range(const char *str);
bool    not_valid_input(int ac, char **av);

// stack_utils
t_stack *create_stack(int ac, char **av);
void    free_stack(t_stack **stack);
void    error_exit(t_stack **a, t_stack **b);
void    print_stack(t_stack *stack, char *name);

#endif