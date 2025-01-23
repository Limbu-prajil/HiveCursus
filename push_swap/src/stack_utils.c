#include "push_swap.h"

// Initialize an empty stack
t_stack *stack_init(void) {
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
      return (NULL);
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;
    return (stack);
}

// Push a value onto the stack
void stack_push(t_stack *stack, int value) {
    int *data = (int *)malloc(sizeof(int));
    if (!data)
      handle_error();
    *data = value;
    t_list *new_node = ft_lstnew(data);
    if (!new_node) {
      free(data);
      handle_error();
    }

    if (stack->head)
      ft_lstadd_front(&stack->head, new_node);
    else {
        stack->head = new_node;
        stack->tail = new_node; // If the stack was empty, set tail to new_node
    }
    stack->size++;
}

// Pop a value from the stack
int stack_pop(t_stack *stack) {
    if (stack_is_empty(stack))
      handle_error();
    t_list *top_node = stack->head;
    int value = *(int *)top_node->content;

    stack->head = top_node->next;
    if (!stack->head)
      stack->tail = NULL; // If the stack is now empty, set tail to NULL
    free(top_node->content);
    free(top_node);
    stack->size--;
    return (value);
}

// Peek at the top value of the stack
int stack_peek(t_stack *stack) {
    if (stack_is_empty(stack))
      handle_error();
    return (*(int *)stack->head->content);
}

// Check if the stack is sorted in ascending order
bool stack_is_sorted(t_stack *stack) {
    t_list *current = stack->head;
    while (current && current->next) {
        if (*(int *)current->content > *(int *)current->next->content)
          return (false);
        current = current->next;
    }
    return (true);
}

// Check if the stack is empty
bool stack_is_empty(t_stack *stack) {
    return (stack->size == 0);
}

// Free the stack and all its nodes
void stack_free(t_stack *stack) {
    ft_lstclear(&stack->head, free);
    free(stack);
}
