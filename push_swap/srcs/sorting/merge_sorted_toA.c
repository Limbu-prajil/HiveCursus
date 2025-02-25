#include <push_swap.h>

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
