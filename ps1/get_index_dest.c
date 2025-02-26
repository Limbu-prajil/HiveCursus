#include "get_index_dest.h"
#include "get_index_min.h"

static int	get_index_max(t_stack stk)
{
	int	max;
	int	i;

	max = 0;
	i = 1;
	while (i <= stk.top)
	{
		if (stk.ary[i] > stk.ary[max])
			max = i;
		i++;
	}
	return (max);
}

// correct position of number to be put on dest stack depends on which stack,
//  a or b, is dest;
//  for example, in b larger numbers are placed on top of smaller ones
int	get_index_dest(t_stack stk, int nb, char dest)
{
	int	i;
	int	start;

	if (dest == 'b')
		start = get_index_min(stk);
	else
		start = get_index_max(stk);
	i = start;
	while (i < start + stk.top)
	{
		if ((dest == 'b' && (stk.ary[i % (stk.top + 1)] > nb || \
		nb > stk.ary[(i + 1) % (stk.top + 1)])) || \
		(dest == 'a' && (stk.ary[i % (stk.top + 1)] < nb || \
		nb < stk.ary[(i + 1) % (stk.top + 1)])))
			i++;
		else
			break ;
	}
	return (i % (stk.top + 1));
}
