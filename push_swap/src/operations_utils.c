#include "push_swap.h"

// Create a new operation
t_operation *create_operation(char *name) {
    t_operation *op = (t_operation *)malloc(sizeof(t_operation));
    if (!op)
      handle_error();
    op->name = name;
    op->next = NULL;
    return (op);
}

// Initialize an empty operation list
t_operation_list *init_operation_list(void) {
    t_operation_list *list = (t_operation_list *)malloc(sizeof(t_operation_list));
    if (!list)
      handle_error();
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return (list);
}

// Add an operation to the list
void add_operation(t_operation_list *list, char *name) {
    t_operation *op = create_operation(name);
    if (!list->head) {
        list->head = op;
        list->tail = op;
    } else {
        list->tail->next = op;
        list->tail = op;
    }
    list->size++;
}

// Print all operations in the list
void print_operations(t_operation_list *list) {
    t_operation *current = list->head;
    while (current) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

// Free the operation list
void free_operation_list(t_operation_list *list) {
    t_operation *current = list->head;
    t_operation *next;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}
