#include "push_swap.h"

// Get chunk size dynamically based on input size
int get_chunk_size(int size)
{
    if (size <= 10) return 2;
    if (size <= 50) return 5;
    if (size <= 100) return 18;
    if (size <= 250) return 25;
    if (size <= 500) return 40;
    return 50;
}

// Copy stack values into an array
int *copy_stack_to_array(t_stack *a, int size)
{
    int *arr = (int *)malloc(sizeof(int) * size);
    if (!arr) return NULL;

    int i = 0;
    while (a && i < size)
    {
        arr[i++] = a->value;
        a = a->next;
    }
    return arr;
}

// QuickSort for pivot selection
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
            if (arr[j] < pivot)
                swap(&arr[++i], &arr[j]);
        swap(&arr[i + 1], &arr[high]);

        quick_sort(arr, low, i);
        quick_sort(arr, i + 2, high);
    }
}

// Find smart pivots using Median of Medians
int *find_pivots(t_stack *a, int size, int chunk_size)
{
    if (size <= 0) return NULL;

    int *arr = copy_stack_to_array(a, size);
    if (!arr) return NULL;

    quick_sort(arr, 0, size - 1);

    int num_chunks = size / chunk_size;
    int *pivots = (int *)malloc(sizeof(int) * num_chunks);
    if (!pivots) { free(arr); return NULL; }

    for (int i = 0; i < num_chunks; i++)
        pivots[i] = arr[(i + 1) * chunk_size - 1];

    free(arr);
    return pivots;
}

// Push chunks to B with minimal rotations
void push_chunks_to_b(t_stack **a, t_stack **b, int *pivots, int num_chunks, int chunk_size)
{
    if (!pivots || !(*a)) return;

    for (int i = 0; i < num_chunks; i++)
    {
        int moves = 0;
        int total_moves = stack_size(*a);

        while (moves < chunk_size && total_moves--)
        {
            if (!(*a)) break;  // Prevent accessing NULL
            if ((*a)->value <= pivots[i])
            {
                pb(a, b);
                moves++;
                if (*b && (*b)->next && (*b)->value < (*b)->next->value)
                    sb(b); // Immediate optimization
            }
            else if ((*a)->value > pivots[i])
                ra(a); // Only rotate if we see large numbers
        }
    }
}

// Find max value in B efficiently
// Get next element to move back to A in correct sequence
int find_max(t_stack *b)
{
	int max = INT_MIN;
	while (b)
	{
		if (b->value > max)
			max = b->value;
		b = b->next;
	}
	return max;
}

// Find the position of a target value in B
int find_position(t_stack *b, int target)
{
    int index = 0;
    while (b)
    {
        if (b->value == target)
            return index;
        index++;
        b = b->next;
    }
    return -1;
}

// Insert sorted chunks back to A efficiently, optimised merging strategy (reducing movement)
void merge_sorted_to_a(t_stack **a, t_stack **b)
{
    while (*b)
    {
        int max_value = find_max(*b);
        int pos = find_position(*b, max_value);
        int size_b = stack_size(*b);
        
        if (pos == -1) break;
		// Rotate B in the optimal direction
        if (pos <= size_b / 2)
            while (*b && (*b)->value != max_value)
                rb(b);
        else
            while (*b && (*b)->value != max_value)
                rrb(b);
        if (*b) pa(a, b);
    }
}

// Optimized sorting algorithm
void sort_algo(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);
    if (size <= 1 || is_sorted(*a) || !(*a)) return;

    int chunk_size = get_chunk_size(size);
    int num_chunks = size / chunk_size;
    int *pivots = find_pivots(*a, size, chunk_size);
    if (!pivots) return;

    push_chunks_to_b(a, b, pivots, num_chunks, chunk_size);
    free(pivots);

    merge_sorted_to_a(a, b);
}