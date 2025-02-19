#include "push_swap.h"

// Function to perform Insertion Sort on a small chunk
static void	insertion_sort(t_stack **a, int size)
{
	int	i;
	int	j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if ((*a)->value > (*a)->next->value)
				sa(a);
			ra(a);
		}
		for (j = 0; j < size - i - 1; j++)
			rra(a);
	}
}

// Function to partition the stack using a pivot
static int	partition(t_stack **a, t_stack **b, int size)
{
	int	pivot;
	int	i;
	int	operations;

	pivot = (*a)->value;
	operations = 0;
	i = 0;
	while (i < size)
	{
		if ((*a)->value < pivot)
			pb(a, b);
		else
			ra(a);
		i++;
		operations++;
	}
	return (operations);
}

// Function to perform hybrid QuickSort
static void	quick_sort(t_stack **a, t_stack **b, int size)
{
	int	operations;

	if (size <= 5)
	{
		insertion_sort(a, size);
		return;
	}

	operations = partition(a, b, size);
	quick_sort(a, b, operations);
	quick_sort(b, a, size - operations);

	while (operations--)
		pa(a, b);
}

// Function to sort stack a using hybrid QuickSort
void	timsort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	quick_sort(a, b, size);
}