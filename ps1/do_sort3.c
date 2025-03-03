#include "push_swap.h"
#include "libft/libft.h"

static void	do_sort3_case01(t_stack *stk)
{
	if (stk->ary[1] < stk->ary[2])
	{
		swap(stk);
		ft_printf("sa\n");
	}
}

static void	do_sort3_case25(t_stack *stk)
{
	rerot(stk);
	ft_printf("rra\n");
	if (stk->ary[1] < stk->ary[2])
	{
		swap(stk);
		ft_printf("sa\n");
	}
}

static void	do_sort3_case34(t_stack *stk)
{
	rot(stk);
	ft_printf("ra\n");
	if (stk->ary[1] < stk->ary[2])
	{
		swap(stk);
		ft_printf("sa\n");
	}
}

//stk pos:  0,   1,   2
//case 0: max, mid, min
//case 1: max, min, mid
//case 2: min, max, mid
//case 3: min, mid, max
//case 4: mid, min, max
//case 5: mid, max, min
void	do_sort3(t_stack *stk)
{
	if (stk->ary[0] > stk->ary[1] && stk->ary[0] > stk->ary[2])
		do_sort3_case01(stk);
	if (stk->ary[1] > stk->ary[0] && stk->ary[1] > stk->ary[2])
		do_sort3_case25(stk);
	if (stk->ary[2] > stk->ary[0] && stk->ary[2] > stk->ary[1])
		do_sort3_case34(stk);
}
