#include "push_swap.h"

// Reverse rotate stack A (shift all elements down by one)
void rra(t_stack *stack_a, t_operation_list *ops) {
    if (stack_a->size < 2)
      return;
    t_list *last = stack_a->tail;
    t_list *second_last = stack_a->head;
    while (second_last->next != last)
      second_last = second_last->next;
    second_last->next = NULL;
    stack_a->tail = second_last;
    ft_lstadd_front(&stack_a->head, last);
    add_operation(ops, "rra");
}

// Reverse rotate stack B (shift all elements down by one)
void rrb(t_stack *stack_b, t_operation_list *ops) {
    if (stack_b->size < 2)
      return;
    t_list *last = stack_b->tail;
    t_list *second_last = stack_b->head;
    while (second_last->next != last)
      second_last = second_last->next;
    second_last->next = NULL;
    stack_b->tail = second_last;
    ft_lstadd_front(&stack_b->head, last);
    add_operation(ops, "rrb");
}

// Reverse rotate both stacks
void rrr(t_stack *stack_a, t_stack *stack_b, t_operation_list *ops) {
    rra(stack_a, ops);
    rrb(stack_b, ops);
    add_operation(ops, "rrr");
}
