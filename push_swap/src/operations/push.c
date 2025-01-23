#include "push_swap.h"

// Push the top element of stack B to stack A
void pa(t_stack *stack_a, t_stack *stack_b, t_operation_list *ops) {
    if (stack_is_empty(stack_b))
      return;
    int value = stack_pop(stack_b);
    stack_push(stack_a, value);
    add_operation(ops, "pa");
}

// Push the top element of stack A to stack B
void pb(t_stack *stack_a, t_stack *stack_b, t_operation_list *ops) {
    if (stack_is_empty(stack_a))
      return;
    int value = stack_pop(stack_a);
    stack_push(stack_b, value);
    add_operation(ops, "pb");
}
