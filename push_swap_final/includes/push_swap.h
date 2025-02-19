#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

// Stack operations
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// Stack utilities
t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_clear(t_stack **stack);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);

// Validation
int		validate_args(int argc, char **argv);

// Sorting
void	sort_stack(t_stack **a, t_stack **b);

// Timsort
void	optimized_sort(t_stack **a, t_stack **b);

// Utilities
void	error_exit(void);

// Print stack a
void	print_stack(t_stack *stack, char *name);

#endif