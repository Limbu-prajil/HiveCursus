#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack {
    int value;
    struct s_stack *prev;
    struct s_stack *next;
} t_stack;

void free_stack(t_stack *stack) {
    while (stack) {
        t_stack *temp = stack;
        stack = stack->next;
        free(temp);
    }
}

void print_stack(t_stack *stack, char *name) {
    printf("%s: ", name);
    while (stack) {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

t_stack *create_node(int value) {
    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
    {
      fprintf(stderr, "Memory allocation failed\n");
      exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

t_stack *find_min(t_stack *a) {
    t_stack *min_node = a;
    while (a) {
        if (a->value < min_node->value)
            min_node = a;
        a = a->next;
    }
    return min_node;
}

void move_to_top(t_stack **a, t_stack *min_node) {
    if (!a || !(*a) || !min_node || *a == min_node)
        return;

    // Loop if min_node is not head/first/top node
    while (*a != min_node) {
        if (min_node->prev == NULL)
            break;

        // Detach min_node from its current position
        if (min_node->prev)
            min_node->prev->next = min_node->next;
        if (min_node->next)
            min_node->next->prev = min_node->prev;

        // Move min_node to the top
        min_node->next = *a;
        (*a)->prev = min_node;
        min_node->prev = NULL;
        *a = min_node;
    }
}

void push_b(t_stack **from, t_stack **to) {
    if (!from || !(*from))
        return;
    t_stack *node = *from;
    *from = (*from)->next;
    if (*from)
        (*from)->prev = NULL;
    node->next = *to;
    if (*to)
        (*to)->prev = node;
    *to = node;
    //printf("Pushed %d to stack B.\n", node->value);
    printf("pb\n");
}

void push_a(t_stack **from, t_stack **to) {
    if (!from || !(*from))
        return;
    t_stack *node = *from;
    *from = (*from)->next;
    if (*from)
        (*from)->prev = NULL;
    node->next = *to;
    if (*to)
        (*to)->prev = node;
    *to = node;
    //printf("Pushed %d to stack A.\n", node->value);
    printf("pa\n");
}

void push_swap_sort(t_stack **a, t_stack **b) {
    while (*a) {
        t_stack *min_node = find_min(*a);
        //printf("Found min: %d\n", min_node->value);
        move_to_top(a, min_node);
        //print_stack(*a, "Stack A before push");
        push_b(a, b);
        //print_stack(*a, "Stack A after push");
        //print_stack(*b, "Stack B after push");
        //printf("--------------------------\n");
    }
    while (*b) {
        push_a(b, a);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: ./push_swap num1 num2 ...\n");
        return 1;
    }
    t_stack *a = NULL, *b = NULL, *new_node;
    for (int i = argc - 1; i > 0; i--) {
        new_node = create_node(atoi(argv[i]));
        new_node->next = a;
        if (a)
            a->prev = new_node;
        a = new_node;
    }
    //print_stack(a, "Stack A (Initial)");
    push_swap_sort(&a, &b);
    //print_stack(a, "Stack A (Sorted)");
    free_stack(a);
    free_stack(b);
    return 0;
}
