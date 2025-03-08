#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/* Node structure for the circular doubly linked list */
typedef struct s_node {
    int value;
    struct s_node *prev;
    struct s_node *next;
} t_node;

/* Stack structure */
typedef struct s_stack {
    t_node *top;
    int size;
} t_stack;

/* Stack operations */
t_node *create_node(int value);
void push(t_stack *stack, t_node *node);
t_node *pop(t_stack *stack);
void swap(t_stack *stack);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);

/* Input parsing and validation */
bool is_valid_integer(char *str);
bool is_duplicate(t_stack *stack, int value);
void parse_input(t_stack *stack, int argc, char **argv);

/* Sorting algorithms */
void sort_three(t_stack *stack);
void push_swap(t_stack *a, t_stack *b);

/* Utility functions */
void print_stack(t_stack *stack); // For debugging purposes
void free_stack(t_stack *stack);  // Free memory allocated for the stack

#endif
