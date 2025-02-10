#include "push_swap.h"

// Helper function to check for duplicates in the stack
static bool has_duplicates(t_stack *stack) {
    t_list *current = stack->head;
    while (current) {
        t_list *runner = current->next;
        while (runner) {
            if (*(int *)current->content == *(int *)runner->content) {
                return true; // Duplicate found
            }
            runner = runner->next;
        }
        current = current->next;
    }
    return false; // No duplicates
}

// Validate input arguments
bool validate_input(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '\0') {
            return false; // Empty argument
        }
        char **tokens = ft_split(argv[i], ' ');
        if (!tokens) {
            return false;
        }
        for (int j = 0; tokens[j]; j++) {
            if (tokens[j][0] == '\0') {
                free(tokens[j]);
                free(tokens);
                return false; // Empty token
            }
            for (int k = 0; tokens[j][k]; k++) {
                if (k == 0 && (tokens[j][k] == '+' || tokens[j][k] == '-')) {
                    continue; // Allow leading + or -
                }
                if (!ft_isdigit(tokens[j][k])) {
                    free(tokens[j]);
                    free(tokens);
                    return false; // Non-digit character
                }
            }
            long num = ft_atol(tokens[j]);
            if (num < INT_MIN || num > INT_MAX) {
                free(tokens[j]);
                free(tokens);
                return false; // Integer overflow
            }
            free(tokens[j]);
        }
        free(tokens);
    }
    return true;
}

// Parse input arguments into stack_a
t_stack *parse_input(int argc, char **argv) {
    t_stack *stack_a = stack_init();
    if (!stack_a) {
        return NULL;
    }
    for (int i = 1; i < argc; i++) {
        char **tokens = ft_split(argv[i], ' ');
        if (!tokens) {
            stack_free(stack_a);
            handle_error();
        }
        for (int j = 0; tokens[j]; j++) {
            if (tokens[j][0] == '\0') {
                free(tokens[j]);
                free(tokens);
                stack_free(stack_a);
                handle_error(); // Empty token
            }
            int num = ft_atoi(tokens[j]);
            stack_push(stack_a, num);
            free(tokens[j]); // Free each token
        }
        free(tokens); // Free the tokens array
    }
    // Check for duplicates
    if (has_duplicates(stack_a)) {
        stack_free(stack_a);
        handle_error();
    }
    return stack_a;
}

// Handle errors by printing a message and exiting
void handle_error(void) {
    ft_putendl_fd("Error either validating or parsing input!", 2);
    exit(1);
}
