#include "libft/libft.h"
#include "swap.h"
#include "push.h"
#include "rot.h"
#include "rerot.h"

int	is_sorted(t_stack a)
{
	int	i;

	i = 0;
	while (i < a.top)
	{
		if (a.ary[i] < a.ary[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	do_both(void (*op)(t_stack *stk), t_stack *a, t_stack *b)
{
	op(a);
	op(b);
}

int	do_op(t_stack *a, t_stack *b, char *opstr)
{
	if (ft_strncmp(opstr, "sa\n", 4) == 0)
		swap(a);
	else if (ft_strncmp(opstr, "sb\n", 4) == 0)
		swap(b);
	else if (ft_strncmp(opstr, "ss\n", 4) == 0)
		do_both(swap, a, b);
	else if (ft_strncmp(opstr, "pa\n", 4) == 0)
		push(a, b);
	else if (ft_strncmp(opstr, "pb\n", 4) == 0)
		push(b, a);
	else if (ft_strncmp(opstr, "ra\n", 4) == 0)
		rot(a);
	else if (ft_strncmp(opstr, "rb\n", 4) == 0)
		rot(b);
	else if (ft_strncmp(opstr, "rr\n", 4) == 0)
		do_both(rot, a, b);
	else if (ft_strncmp(opstr, "rra\n", 5) == 0)
		rerot(a);
	else if (ft_strncmp(opstr, "rrb\n", 5) == 0)
		rerot(b);
	else if (ft_strncmp(opstr, "rrr\n", 5) == 0)
		do_both(rerot, a, b);
	else
		return (0);
	return (1);
}

int	check_bonus(t_stack *a, t_stack *b)
{
	char	*opstr;

	opstr = get_next_line(0);
	while (opstr)
	{
		if (!do_op(a, b, opstr))
		{
			while (opstr)
			{
				free (opstr);
				opstr = get_next_line(0);
			}
			return (0);
		}
		free (opstr);
		opstr = get_next_line(0);
	}
	if (is_sorted(*a) && b->top == -1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (1);
}
