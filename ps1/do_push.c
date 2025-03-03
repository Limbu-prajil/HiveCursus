#include "push_swap.h"
#include "libft/libft.h"

static void	prep_common(t_stack *a, t_stack *b, t_rot act)
{
	while (act.common)
	{
		if (act.common > 0)
		{
			rot(a);
			rot(b);
			act.common--;
			ft_printf("rr\n");
		}
		else if (act.common < 0)
		{
			rerot(a);
			rerot(b);
			act.common++;
			ft_printf("rrr\n");
		}
	}
}

static void	prep_src(t_stack *a, t_rot act, char src)
{
	while (act.count_a)
	{
		if (act.count_a > 0)
		{
			rot(a);
			act.count_a--;
			ft_printf("r%c\n", src);
		}
		else
		{
			rerot(a);
			act.count_a++;
			ft_printf("rr%c\n", src);
		}
	}
}

static void	prep_dst(t_stack *b, t_rot act, char dest)
{
	while (act.count_b)
	{
		if (act.count_b > 0)
		{
			rot(b);
			act.count_b--;
			ft_printf("r%c\n", dest);
		}
		else
		{
			rerot(b);
			act.count_b++;
			ft_printf("rr%c\n", dest);
		}
	}
}

void	do_push(t_stack *src, t_stack *dst, t_rot act, char dst_stk)
{
	prep_common(src, dst, act);
	if (dst_stk == 'b')
	{
		prep_src(src, act, 'a');
		prep_dst(dst, act, 'b');
	}
	else
	{
		prep_src(src, act, 'b');
		prep_dst(dst, act, 'a');
	}
	if (push(dst, src))
		ft_printf("p%c\n", dst_stk);
}
