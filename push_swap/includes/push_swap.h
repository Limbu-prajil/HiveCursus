#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"

/* Define the structure for a stack node (using libft's t_list)
typedef struct s_list {
    void *content;              // Pointer to integer stored in the node
    struct s_list *next;        // Pointer to the next node
} t_list; */

// Define the structure for a stack
typedef struct s_stack {
    t_list *head;               // Pointer to the top of the stack
    t_list *tail;               // Pointer to the bottom of the stack
    int size;                   // Number of elements in the stack
} t_stack;

// Define the structure for an operation
typedef struct s_operation {
    char *name;                  // Name of the operation (e.g., "sa", "pb", "ra")
    struct s_operation *next;    // Pointer to the next operation
} t_operation;

// Define the structure for a list of operations
typedef struct s_operation_list {
    t_operation *head;           // Pointer to the first operation
    t_operation *tail;           // Pointer to the last operation
    int size;                    // Number of operations
} t_operation_list;

// Stack utility functions
t_stack *stack_init(void);
void stack_push(t_stack *stack, int value);
int stack_pop(t_stack *stack);
bool stack_is_empty(t_stack *stack);
void stack_free(t_stack *stack);
int stack_peek(t_stack *stack);
bool stack_is_sorted(t_stack *stack);

// Input validation and parsing
bool validate_input(int argc, char **argv);
t_stack *parse_input(int argc, char **argv);

// Error handling
void handle_error(void);

// Sorting algorithms
void handle_simple_case(t_stack *stack_a, t_operation_list *ops);
void handle_medium_case(t_stack *stack_a, t_stack *stack_b, t_operation_list *ops);

// Operations for stack
void sa(t_stack *stack_a, t_operation_list *ops);
void sb(t_stack *stack_b, t_operation_list *ops);
void ss(t_stack *stack_a, t_stack *stack_b, t_operation_list *ops);
void pa(t_stack *stack_a, t_stack *stack_b, t_operation_list *ops);
void pb(t_stack *stack_a, t_stack *stack_b, t_operation_list *ops);
void ra(t_stack *stack_a, t_operation_list *ops);
void rb(t_stack *stack_b, t_operation_list *ops);
void rr(t_stack *stack_a, t_stack *stack_b, t_operation_list *ops);
void rra(t_stack *stack_a, t_operation_list *ops);
void rrb(t_stack *stack_b, t_operation_list *ops);
void rrr(t_stack *stack_a, t_stack *stack_b, t_operation_list *ops);

// Operation list functions
t_operation *create_operation(char *name);
t_operation_list *init_operation_list(void);
void add_operation(t_operation_list *list, char *name);
void print_operations(t_operation_list *list);
void free_operation_list(t_operation_list *list);

#endif
