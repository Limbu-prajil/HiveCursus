#include "push_swap.h"

int	has_duplicate(t_stack stk)
{
	int	i;
	int	j;

	i = 0;
	while (i <= stk.top)
	{
		j = 0;
		while (j < i)
		{
			if (stk.ary[i] == stk.ary[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	not_sorted(t_stack a)
{
	int	i;

	i = 0;
	while (i < a.top)
	{
		if (a.ary[i] < a.ary[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (1);
	if (!init_stack(&a, argv + 1, 1) || has_duplicate(a))
	{
		free(a.ary);
		write(2, "Error\n", 6);
		return (1);
	}
	if (!init_stack(&b, argv + 1, 0))
	{
		free(a.ary);
		free(b.ary);
		write(2, "Error\n", 6);
		return (1);
	}
	if (not_sorted(a))
		sort(&a, &b);
	free(a.ary);
	free(b.ary);
}
