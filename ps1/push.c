#include "push.h"

int	push(t_stack *dest, t_stack *src)
{
	if (src->top >= 0)
	{
		dest->top++;
		dest->ary[dest->top] = src->ary[src->top];
		src->top--;
		return (1);
	}
	return (0);
}
