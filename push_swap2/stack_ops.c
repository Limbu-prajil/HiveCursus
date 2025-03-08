#include "push_swap.h"

t_node *create_node(int value) {
    t_node *node = (t_node *)malloc(sizeof(t_node));
    if (!node) return NULL;
    node->value = value;
    node->prev = node;
    node->next = node;
    return node;
}

void push(t_stack *stack, t_node *node) {
    if (!stack || !node) return;
    if (stack->top) {
        node->next = stack->top;
        node->prev = stack->top->prev;
        stack->top->prev->next = node;
        stack->top->prev = node;
    }
    stack->top = node;
    stack->size++;
}

t_node *pop(t_stack *stack) {
    if (!stack || !stack->top) return NULL;
    t_node *node = stack->top;
    if (stack->size == 1) {
        stack->top = NULL;
    } else {
        stack->top->next->prev = stack->top->prev;
        stack->top->prev->next = stack->top->next;
        stack->top = stack->top->next;
    }
    node->next = node;
    node->prev = node;
    stack->size--;
    return node;
}

void swap(t_stack *stack) {
    if (!stack || stack->size < 2) return;
    t_node *first = stack->top;
    t_node *second = first->next;
    first->next = second->next;
    second->next->prev = first;
    second->next = first;
    second->prev = first->prev;
    first->prev->next = second;
    first->prev = second;
    stack->top = second;
}

void rotate(t_stack *stack) {
    if (!stack || stack->size < 2) return;
    stack->top = stack->top->next;
}

void reverse_rotate(t_stack *stack) {
    if (!stack || stack->size < 2) return;
    stack->top = stack->top->prev;
}
