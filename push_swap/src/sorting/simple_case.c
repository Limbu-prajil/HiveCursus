#include "push_swap.h"

// Sort a stack of 2 numbers
void sort_two(t_stack *stack_a, t_operation_list *ops) {
    if (stack_a->head->content > stack_a->head->next->content)
      sa(stack_a, ops);
}

// Sort a stack of 3 numbers
void sort_three(t_stack *stack_a, t_operation_list *ops) {
    int a = *(int *)stack_a->head->content;
    int b = *(int *)stack_a->head->next->content;
    int c = *(int *)stack_a->head->next->next->content;

    if (a > b && b < c && a < c)
      sa(stack_a, ops);
    else if (a > b && b > c) {
      sa(stack_a, ops);
      rra(stack_a, ops);
    }
    else if (a > b && b < c && a > c)
      ra(stack_a, ops);
    else if (a < b && b > c && a < c) {
      sa(stack_a, ops);
      ra(stack_a, ops);
    }
    else if (a < b && b > c && a > c)
      rra(stack_a, ops);
}

// Handle simple cases (2-3 numbers)
void handle_simple_case(t_stack *stack_a, t_operation_list *ops) {
    if (stack_a->size == 2)
      sort_two(stack_a, ops);
    else if (stack_a->size == 3)
      sort_three(stack_a, ops);
}
