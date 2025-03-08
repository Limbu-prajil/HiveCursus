#include "push_swap.h"

bool is_valid_integer(char *str) {
    if (!str) return false;
    if (*str == '-' || *str == '+') str++;
    while (*str) {
        if (*str < '0' || *str > '9') return false;
        str++;
    }
    return true;
}

bool is_duplicate(t_stack *stack, int value) {
    if (!stack || !stack->top) return false;
    t_node *current = stack->top;
    do {
        if (current->value == value) return true;
        current = current->next;
    } while (current != stack->top);
    return false;
}

void parse_input(t_stack *stack, int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        if (!is_valid_integer(argv[i])) {
            fprintf(stderr, "Error\n");
            exit(EXIT_FAILURE);
        }
        long value = atol(argv[i]);
        if (value < INT_MIN || value > INT_MAX) {
            fprintf(stderr, "Error\n");
            exit(EXIT_FAILURE);
        }
        if (is_duplicate(stack, (int)value)) {
            fprintf(stderr, "Error\n");
            exit(EXIT_FAILURE);
        }
        push(stack, create_node((int)value));
    }
}
