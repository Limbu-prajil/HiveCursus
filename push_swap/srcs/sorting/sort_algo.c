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

// Optimized sorting algorithm
void sort_algo(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);
    if (size <= 1 || is_sorted(*a) || !(*a))
    	return ;
    int chunk_size = get_chunk_size(size);
    int num_chunks = size / chunk_size;
    int *pivots = find_pivots(*a, size, chunk_size);
    if (!pivots) return;

    push_chunks_to_b(a, b, pivots, num_chunks, chunk_size);
    free(pivots);

    merge_sorted_to_a(a, b);
}

// Sort stack using optimized sorting algorithm
void sort_stack(t_stack **a, t_stack **b)
{
    int size;

    size = stack_size(*a);
    if (size == 2)
        sa(a);
    else if (size == 3)
        sort_three(a);
    else
        sort_algo(a, b);
}
