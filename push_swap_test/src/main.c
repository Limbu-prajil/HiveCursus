#include "push_swap.h"

int main(int argc, char **argv) {
    t_stack *stack_a;
    t_stack *stack_b;
    t_operation_list *ops;

    // Validate empty argument
    if (argc == 1)
    {
      printf("Usage: ./push_swap <list of ints>");
      return (0);
    }

    // Validate input
    if (!validate_input(argc, argv))
      handle_error();

    // Parse input and initialize stack_a
    stack_a = parse_input(argc, argv);
    if (!stack_a)
      handle_error();
    if (stack_is_sorted(stack_a))
      return (0);

    // Initialize stack_b
    stack_b = stack_init();
    if (!stack_b)
    {
      stack_free(stack_a);
      handle_error();
    }

    // Initialize operation list
    ops = init_operation_list();

    // Implemented sorting logic here
    // Determine input size and call appropriate sorting function
    if (stack_a->size <= 3)
      handle_simple_case(stack_a, ops); // Use hardcoded sequences
    else
      handle_medium_case(stack_a, stack_b, ops); // Use Timsort

    // Print the sequence of operations
    print_operations(ops);

    // Free stacks before exiting
    stack_free(stack_a);
    stack_free(stack_b);
    free_operation_list(ops);
    return (0);
}
