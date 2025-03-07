#include "push_swap.h"
#include "libft/libft.h"

static int	is_int(char *str, int len)
{
	int		num_from_str;
	char	*str_from_num;
	int		res;

	num_from_str = ft_atoi(str);
	str_from_num = ft_itoa(num_from_str);
	if (!str_from_num)
		return (0);
	if (num_from_str >= 0 && ft_strchr("+-", *str))
	{
		str++;
		len--;
	}
	res = !ft_strncmp(str_from_num, str, len);
	free(str_from_num);
	return (res);
}

int	count_elements(char **strary)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = 0;
	while (strary[i])
	{
		j = -1;
		while (strary[i][++j])
		{
			if (ft_strchr("\t\n\v\f\r ", strary[i][j]))
				continue ;
			num++;
			while (!ft_strchr("\t\n\v\f\r ", strary[i][j]))
				j++;
			j--;
		}
		i++;
	}
	return (num);
}

int	*init_stack(t_stack *stk, char **strary, int fillmode)
{
	int	j;
	int	start;

	stk->top = 0;
	stk->sz = count_elements(strary);
	stk->ary = ft_calloc(stk->sz, sizeof(stk->ary));
	while (fillmode && stk->ary && *strary)
	{
		j = -1;
		while ((*strary)[++j])
		{
			if (ft_strchr("\t\n\v\f\r ", (*strary)[j]))
				continue ;
			start = j;
			while (!ft_strchr("\t\n\v\f\r ", (*strary)[j]))
				j++;
			if (is_int(*strary + start, j-- - start))
				stk->ary[stk->sz - 1 - stk->top++] = ft_atoi(*strary + start);
			else
				return (0);
		}
		strary++;
	}
	stk->top--;
	return (stk->ary);
}
