#include "rerot.h"
#include "libft/libft.h"

void	rerot(t_stack *stk)
{
	int	tmp;

	if (stk->top > 0)
	{
		tmp = stk->ary[0];
		ft_memmove(stk->ary, stk->ary + 1, stk->top * sizeof(*stk->ary));
		stk->ary[stk->top] = tmp;
	}
}
