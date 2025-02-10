#include "push_swap.h"

// Rotate stack A (shift all elements up by one)
void ra(t_stack *stack_a, t_operation_list *ops) {
    if (stack_a->size < 2)
      return;
    t_list *first = stack_a->head;
    stack_a->head = first->next;
    first->next = NULL;
    ft_lstadd_back(&stack_a->head, first);
    add_operation(ops, "ra");
}

// Rotate stack B (shift all elements up by one)
void rb(t_stack *stack_b, t_operation_list *ops) {
    if (stack_b->size < 2)
      return;
    t_list *first = stack_b->head;
    stack_b->head = first->next;
    first->next = NULL;
    ft_lstadd_back(&stack_b->head, first);
    add_operation(ops, "rb");
}

// Rotate both stacks
void rr(t_stack *stack_a, t_stack *stack_b, t_operation_list *ops) {
    ra(stack_a, ops);
    rb(stack_b, ops);
    add_operation(ops, "rr");
}
