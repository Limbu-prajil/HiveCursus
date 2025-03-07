#include "push_swap.h"

int	get_index_min(t_stack stk)
{
	int	min;
	int	i;

	min = 0;
	i = 1;
	while (i <= stk.top)
	{
		if (stk.ary[i] < stk.ary[min])
			min = i;
		i++;
	}
	return (min);
}
