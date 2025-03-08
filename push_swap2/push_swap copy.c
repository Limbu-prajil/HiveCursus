#include "push_swap.h"

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

void push_swap(t_stack *a, t_stack *b) {
    while (a->size > 3) {
        push(b, pop(a));
        printf("pb\n");
    }
    sort_three(a);
    while (b->size > 0) {
        push(a, pop(b));
        printf("pa\n");
    }
}
