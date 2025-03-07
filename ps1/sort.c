#include "push_swap.h"
#include "libft/libft.h"

static int	absval(int num)
{
	if (num < 0)
		return (-1 * num);
	else
		return (num);
}

static t_rot	best_push_ab(t_stack a, t_stack b)
{
	t_rot	best;
	t_rot	test;
	int		min;
	int		count;
	int		i;

	best = whatif_push_ab(0, a, b, 'b');
	min = absval(best.common) + absval(best.count_a) + absval(best.count_b);
	i = 1;
	while (i <= a.top)
	{
		test = whatif_push_ab(i, a, b, 'b');
		count = absval(test.common) + absval(test.count_a) + \
		absval(test.count_b);
		if (count < min)
		{
			best = test;
			min = count;
		}
		i++;
	}
	return (best);
}

static void	min_to_top(t_stack *a)
{
	int	min_idx;
	int	min_val;

	min_idx = get_index_min(*a);
	min_val = a->ary[min_idx];
	while (a->ary[a->top] != min_val)
	{
		if (min_idx > a->top / 2)
		{
			rot(a);
			ft_printf("ra\n");
		}
		else
		{
			rerot(a);
			ft_printf("rra\n");
		}
	}
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->top > 2 && push(b, a))
		ft_printf("pb\n");
	while (a->top > 2)
		do_push(a, b, best_push_ab(*a, *b), 'b');
	do_sort3(a);
	while (b->top >= 0)
		do_push(b, a, whatif_push_ab(b->top, *b, *a, 'a'), 'a');
	min_to_top(a);
}
