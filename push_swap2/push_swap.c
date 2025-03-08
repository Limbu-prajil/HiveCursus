#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Node structure for the circular doubly linked list
typedef struct s_node {
    int value;
    struct s_node *prev;
    struct s_node *next;
} t_node;

// Stack structure
typedef struct s_stack {
    t_node *top;
    int size;
} t_stack;

// Function prototypes
t_node *create_node(int value);
void push(t_stack *stack, t_node *node);
t_node *pop(t_stack *stack);
void swap(t_stack *stack);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);
void print_stack(t_stack *stack);
void free_stack(t_stack *stack);
void sort_three(t_stack *stack);
void sort_two(t_stack *stack);
void push_swap(t_stack *a, t_stack *b);

// Create a new node
t_node *create_node(int value) {
    t_node *node = (t_node *)malloc(sizeof(t_node));
    if (!node) return NULL;
    node->value = value;
    node->prev = node;
    node->next = node;
    return node;
}

// Push a node onto the stack
void push(t_stack *stack, t_node *node) {
    if (!stack || !node) return;
    if (stack->top) {
        node->next = stack->top;
        node->prev = stack->top->prev;
        stack->top->prev->next = node;
        stack->top->prev = node;
    }
    stack->top = node;
    stack->size++;
}

// Pop the top node from the stack
t_node *pop(t_stack *stack) {
    if (!stack || !stack->top) return NULL;
    t_node *node = stack->top;
    if (stack->size == 1) {
        stack->top = NULL;
    } else {
        stack->top->next->prev = stack->top->prev;
        stack->top->prev->next = stack->top->next;
        stack->top = stack->top->next;
    }
    node->next = node;
    node->prev = node;
    stack->size--;
    return node;
}

// Swap the top two nodes of the stack
void swap(t_stack *stack) {
    if (!stack || stack->size < 2) return;
    t_node *first = stack->top;
    t_node *second = first->next;
    first->next = second->next;
    second->next->prev = first;
    second->next = first;
    second->prev = first->prev;
    first->prev->next = second;
    first->prev = second;
    stack->top = second;
}

// Rotate the stack (move the top node to the bottom)
void rotate(t_stack *stack) {
    if (!stack || stack->size < 2) return;
    stack->top = stack->top->next;
}

// Reverse rotate the stack (move the bottom node to the top)
void reverse_rotate(t_stack *stack) {
    if (!stack || stack->size < 2) return;
    stack->top = stack->top->prev;
}

// Print the stack (for debugging purposes)
void print_stack(t_stack *stack) {
    if (!stack || !stack->top) return;
    t_node *current = stack->top;
    while (1) {
        printf("%d ", current->value);
        current = current->next;
        if (current == stack->top) break;
    }
    printf("\n");
}

// Free the stack
void free_stack(t_stack *stack) {
    if (!stack || !stack->top) return;
    t_node *current = stack->top;
    t_node *next;
    while (1) {
        next = current->next;
        free(current);
        current = next;
        if (current == stack->top) break;
    }
    stack->top = NULL;
    stack->size = 0;
}

// Sort a stack of two elements
void sort_two(t_stack *stack) {
    if (!stack || stack->size != 2) return;
    if (stack->top->value > stack->top->next->value) {
        swap(stack);
    }
}

// Sort a stack of three elements
void sort_three(t_stack *stack) {
    if (!stack || stack->size != 3) return;
    t_node *first = stack->top;
    t_node *second = first->next;
    t_node *third = second->next;

    if (first->value > second->value && second->value < third->value && first->value < third->value) {
        swap(stack);
    } else if (first->value > second->value && second->value > third->value) {
        swap(stack);
        reverse_rotate(stack);
    } else if (first->value > second->value && second->value < third->value && first->value > third->value) {
        rotate(stack);
    } else if (first->value < second->value && second->value > third->value && first->value < third->value) {
        swap(stack);
        rotate(stack);
    } else if (first->value < second->value && second->value > third->value && first->value > third->value) {
        reverse_rotate(stack);
    }
}

// Find the minimum value in stack B
int find_min_b(t_stack *b) {
    if (!b || !b->top) return INT_MAX;
    int min_b = b->top->value;
    t_node *current = b->top->next;
    while (current != b->top) {
        if (current->value < min_b) min_b = current->value;
        current = current->next;
    }
    return min_b;
}

// Find the closest minimum and maximum values in stack A compared to min_b
void find_min_max_to_push(t_stack *a, int min_b, int *min_to_push, int *max_to_push) {
    if (!a || !a->top) return;

    // Initialize min_to_push and max_to_push
    *min_to_push = INT_MAX;
    *max_to_push = INT_MIN;

    t_node *current = a->top;
    while (1) {
        if (current->value < min_b && current->value > *min_to_push) {
            *min_to_push = current->value;
        }
        if (current->value > min_b && current->value < *max_to_push) {
            *max_to_push = current->value;
        }
        current = current->next;
        if (current == a->top) break;
    }

    // If no valid min_to_push or max_to_push is found, set them to the top of stack A
    if (*min_to_push == INT_MAX) {
        *min_to_push = a->top->value;
    }
    if (*max_to_push == INT_MIN) {
        *max_to_push = a->top->value;
    }
}

// Push-Swap algorithm
void push_swap(t_stack *a, t_stack *b) {
    // Push first two elements to stack B
    push(b, pop(a));
    printf("pb\n");
    push(b, pop(a));
    printf("pb\n");
    swap(b);
    printf("sb\n");

    // Push remaining elements to stack B
    while (a->size > 3) {
        // Find min_b (minimum value in stack B)
        int min_b = find_min_b(b);

        // Find min_to_push and max_to_push in stack A
        int min_to_push, max_to_push;
        find_min_max_to_push(a, min_b, &min_to_push, &max_to_push);

        // Print min_to_push and max_to_push
        printf("min_to_push: %d, max_to_push: %d\n", min_to_push, max_to_push);

        // Push the chosen element to stack B
        if (a->top->value == min_to_push || a->top->value == max_to_push) {
            push(b, pop(a));
            printf("pb\n");
        } else {
            rotate(a);
            printf("ra\n");
        }

        // Maintain stack B in descending order
        if (b->size > 1 && b->top->value < b->top->next->value) {
            swap(b);
            printf("sb\n");
        }
    }

    // Check if all values in stack A are greater than the maximum value in stack B
    bool all_greater = true;
    int max_b = INT_MIN;
    t_node *current_b = b->top;
    if (current_b) {
        while (1) {
            if (current_b->value > max_b) max_b = current_b->value;
            current_b = current_b->next;
            if (current_b == b->top) break;
        }
    }

    t_node *current_a = a->top;
    if (current_a) {
        while (1) {
            if (current_a->value <= max_b) {
                all_greater = false;
                break;
            }
            current_a = current_a->next;
            if (current_a == a->top) break;
        }
    }

    // Sort stack A if all values are greater than the maximum value in stack B
    if (all_greater) {
        if (a->size == 3) {
            sort_three(a);
        } else if (a->size == 2) {
            sort_two(a);
        }
    }

    // Push all elements back to stack A
    while (b->size > 0) {
        push(a, pop(b));
        printf("pa\n");
    }
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error\n");
        return EXIT_FAILURE;
    }

    t_stack a = {NULL, 0};
    t_stack b = {NULL, 0};

    // Parse input and initialize stack A
    for (int i = 1; i < argc; i++) {
        int value = atoi(argv[i]);
        push(&a, create_node(value));
    }

    // Print initial stack A
    printf("Initial stack A: ");
    print_stack(&a);

    // Sort stack A
    push_swap(&a, &b);

    // Print final stack A
    printf("Final stack A: ");
    print_stack(&a);

    // Free the stacks
    free_stack(&a);
    free_stack(&b);

    return EXIT_SUCCESS;
}
