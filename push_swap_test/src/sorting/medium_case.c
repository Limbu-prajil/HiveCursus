#include "push_swap.h"

// Function to find the minimum value in a stack
int find_min(t_stack *stack) {
    int min = INT_MAX;
    t_list *current = stack->head;

    while (current) {
        if (*(int *)current->content < min)
          min = *(int *)current->content;
        current = current->next;
    }
    return (min);
}

// Function to find the maximum value in a stack
int find_max(t_stack *stack) {
    int max = INT_MIN;
    t_list *current = stack->head;

    while (current) {
        if (*(int *)current->content > max)
          max = *(int *)current->content;
        current = current->next;
    }
    return (max);
}

// Function to merge two sorted runs in the stack
void merge_runs(t_stack *stack_a, t_stack *stack_b, int run_size, t_operation_list *ops) {
    int a_size = stack_a->size;
    int b_size = 0;

    while (a_size > 0) {
        // Push the first run from stack_a to stack_b
        for (int i = 0; i < run_size && a_size > 0; i++) {
            pb(stack_a, stack_b, ops);
            a_size--;
            b_size++;
        }

        // Push the second run from stack_a to stack_b
        for (int i = 0; i < run_size && a_size > 0; i++) {
            pb(stack_a, stack_b, ops);
            a_size--;
            b_size++;
        }

        // Merge the two runs back into stack_a
        while (b_size > 0) {
            int min_b = find_min(stack_b);
            int max_b = find_max(stack_b);

            if (*(int *)stack_b->head->content == min_b) {
                pa(stack_a, stack_b, ops);
            } else if (*(int *)stack_b->head->content == max_b) {
                pa(stack_a, stack_b, ops);
                ra(stack_a, ops);
            } else {
                rb(stack_b, ops);
            }
            b_size--;
        }
    }
}

// Timsort implementation for medium cases (4-500 numbers)
void timsort(t_stack *stack_a, t_stack *stack_b, t_operation_list *ops) {
    int run_size = 32; // Initial run size

    while (run_size < stack_a->size) {
        // Identify and merge runs
        merge_runs(stack_a, stack_b, run_size, ops);
        run_size *= 2; // Double the run size for the next iteration
    }
}

// Handle medium cases (4 or more numbers)
void handle_medium_case(t_stack *stack_a, t_stack *stack_b, t_operation_list *ops) {
    // Check if the stack is reverse-sorted
    bool is_reverse_sorted = true;
    t_list *current = stack_a->head;
    while (current && current->next) {
        if (*(int *)current->content < *(int *)current->next->content) {
            is_reverse_sorted = false;
            break;
        }
        current = current->next;
    }

    if (is_reverse_sorted) {
        // Handle reverse-sorted stack
        while (stack_a->size > 0) {
            pb(stack_a, stack_b, ops);
        }
        while (stack_b->size > 0) {
            pa(stack_a, stack_b, ops);
        }
    } else {
        // Use Timsort for medium cases
        timsort(stack_a, stack_b, ops);
    }
}
