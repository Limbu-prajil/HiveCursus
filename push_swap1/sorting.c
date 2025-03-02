#include "push_swap.h"

t_stack *find_min(t_stack *stack)
{
    t_stack *min = stack;
    t_stack *current = stack->next;

    while (current != stack)
    {
        if (current->value < min->value)
            min = current;
        current = current->next;
    }
    return min;
}

t_stack *find_max(t_stack *stack)
{
    t_stack *max = stack;
    t_stack *current = stack->next;

    while (current != stack)
    {
        if (current->value > max->value)
            max = current;
        current = current->next;
    }
    return max;
}

void move_to_top(t_stack **stack, t_stack *node)
{
    int distance = 0;
    t_stack *temp = *stack;

    while (temp != node)
    {
        temp = temp->next;
        distance++;
    }

    int size = stack_size(*stack);
    if (distance <= size / 2)
    {
        while (*stack != node)
            rotate(stack, 'a');
    }
    else
    {
        while (*stack != node)
            reverse_rotate(stack, 'a');
    }
}


int stack_size(t_stack *stack)
{
    int size = 0;
    t_stack *start = stack;

    if (!stack)
        return 0;
    do {
        size++;
        stack = stack->next;
    } while (stack != start);
    return size;
}

void sort_three(t_stack **a)
{
    int first = (*a)->value;
    int second = (*a)->next->value;
    int third = (*a)->next->next->value;

    if (first > second && second < third && first < third)
        swap(a, 'a');
    else if (first > second && second > third)
    {
        swap(a, 'a');
        reverse_rotate(a, 'a');
    }
    else if (first > second && second < third && first > third)
        rotate(a, 'a');
    else if (first < second && second > third && first < third)
    {
        swap(a, 'a');
        rotate(a, 'a');
    }
    else if (first < second && second > third && first > third)
        reverse_rotate(a, 'a');
}

void sort_five(t_stack **a, t_stack **b)
{
    t_stack *min_node;

    // Push two smallest numbers to B
    while (stack_size(*a) > 3)
    {
        min_node = find_min(*a);
        move_to_top(a, min_node);  // Move min to the top of A
        push(a, b, 'b');  // Push to B
    }

    // Sort the remaining three numbers in A
    sort_three(a);

    // Ensure B is in descending order before pushing back to A
    if ((*b)->value < (*b)->next->value)
        swap(b, 'b');

    // Push back to A in sorted order
    push(b, a, 'a');
    push(b, a, 'a');
}


void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) // FIXED: Renamed from heapsort
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// Helper function to find a node by its value
t_stack *find_node_by_value(t_stack *stack, int value) // FIXED: Added implementation
{
    t_stack *start = stack;
    if (!stack)
        return NULL;
    do {
        if (stack->value == value)
            return stack;
        stack = stack->next;
    } while (stack != start);
    return NULL;
}

void sort_large(t_stack **a, t_stack **b, int size)
{
    int *arr = malloc(size * sizeof(int));
    if (!arr)
        return;

    // Copy stack into array and sort it
    t_stack *temp = *a;
    for (int i = 0; i < size; i++)
    {
        arr[i] = temp->value;
        temp = temp->next;
    }
    heap_sort(arr, size);

    // Push numbers to B in small chunks
    int chunk_size = size / 50;  // Split into 5 chunks
    int index = 0;

    while (index < size)
    {
        int limit = index + chunk_size;
        if (limit > size)
            limit = size;

        for (int i = index; i < limit; i++)
        {
            t_stack *node = find_node_by_value(*a, arr[i]);
            move_to_top(a, node);
            push(a, b, 'b');

            // If top of B is smaller than mid, rotate to balance
            if (stack_size(*b) > 1 && (*b)->value < arr[size / 2])
                rotate(b, 'b');
        }
        index += chunk_size;
    }

    // Push back to A using optimized moves
    while (*b)
    {
        t_stack *max_node = find_max(*b);
        move_to_top(b, max_node);
        push(b, a, 'a');
    }

    free(arr);
}
