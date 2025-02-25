#include "push_swap.h"

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
