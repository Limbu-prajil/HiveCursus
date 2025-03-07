#include "push_swap.h"

void	swap(t_stack *stk)
{
	int	tmp;

	if (stk->top > 0)
	{
		tmp = stk->ary[stk->top - 1];
		stk->ary[stk->top - 1] = stk->ary[stk->top];
		stk->ary[stk->top] = tmp;
	}
}
