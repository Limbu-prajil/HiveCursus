#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

/* Stack Structure */
typedef struct s_stack
{
    int             value;
    struct s_stack  *prev;
    struct s_stack  *next;
} t_stack;

/* Parsing */
t_stack *parse_input(int argc, char **argv);
void add_to_stack(t_stack **stack, int value);
void    free_stack(t_stack **stack);  // Updated to take a double pointer

/* Stack operations */
void    swap(t_stack **stack, char stack_name);
void    push(t_stack **from, t_stack **to, char stack_name);
void    rotate(t_stack **stack, char stack_name);
void    reverse_rotate(t_stack **stack, char stack_name);

/* Sorting algorithms */
void    push_swap(t_stack **a, t_stack **b);
void    sort_three(t_stack **a);
void    sort_five(t_stack **a, t_stack **b);
void    sort_large(t_stack **a, t_stack **b, int size);
void    heap_sort(int arr[], int n);

/* Utility functions */
int     is_sorted(t_stack *stack);
int     stack_size(t_stack *stack);
void    print_stack(t_stack *stack, char name);  // Updated to match function definition
void    exit_error(const char *message);  // Updated to match function definition
void    move_to_top(t_stack **stack, t_stack *node);
t_stack *find_min(t_stack *stack);

/* Libft functions */
size_t  ft_strlen(const char *str);  // Ensure this function is defined elsewhere

#endif
