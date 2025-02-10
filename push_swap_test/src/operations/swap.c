#include "push_swap.h"

// Swap the first two elements of stack A
void sa(t_stack *stack_a, t_operation_list *ops) {
    if (stack_a->size < 2)
      return;
    t_list *first = stack_a->head;
    t_list *second = first->next;
    int temp = *(int *)first->content;
    *(int *)first->content = *(int *)second->content;
    *(int *)second->content = temp;
    add_operation(ops, "sa");
}

// Swap the first two elements of stack B
void sb(t_stack *stack_b, t_operation_list *ops) {
    if (stack_b->size < 2)
      return;
    t_list *first = stack_b->head;
    t_list *second = first->next;
    first->next = second->next;
    second->next = first;
    stack_b->head = second;
    add_operation(ops, "sb");
}

// Swap the first two elements of both stacks
void ss(t_stack *stack_a, t_stack *stack_b, t_operation_list *ops) {
    sa(stack_a, ops);
    sb(stack_b, ops);
    add_operation(ops, "ss");
}
