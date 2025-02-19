#include "push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	if (is_sorted(*a))
		return;
	optimized_sort(a, b);
}