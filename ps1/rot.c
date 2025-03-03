#include "push_swap.h"
#include "libft/libft.h"

void	rot(t_stack *stk)
{
	int	tmp;

	if (stk->top > 0)
	{
		tmp = stk->ary[stk->top];
		ft_memmove(stk->ary + 1, stk->ary, stk->top * sizeof(*stk->ary));
		stk->ary[0] = tmp;
	}
}
