#include "../../inc/push_swap.h"
#include <stdio.h>

long long	ft_atoi_ps(const char *nptr)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	sign = 1;
	if (nptr[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	res = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * res);
}

void	init_mult(int argc, char **argv, t_data *stacks)
{
	int		i;
	t_list	*tmp;

	if (!check_asciinbr(argv))
		error_msg();
	i = 0;
	while (i < argc - 1)
	{
		tmp = ft_lstnew(ft_atoi_ps(argv[i]));
		ft_lstadd_back(stacks, tmp);
		if (stacks->a->nbr > INT_MAX || stacks->a->nbr < INT_MIN)
		{
			free_stack(stacks->a);
			error_msg();
		}
		i++;
	}
}

void	init_string(char **argv, t_data *stacks)
{
	char	**nbrs;
	int		i;
	long long	nbr;		
	t_list	*tmp;

	nbrs = ft_split(argv[0], ' ');
	if (!check_asciinbr(nbrs))
	{
		free_array(nbrs);
		error_msg();
	}
	i = 0;
	while (nbrs[i])
	{
		nbr = ft_atoi_ps(nbrs[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
		{	
			free_array(nbrs);
			free_stack(stacks->a);
			error_msg();
		}
		tmp = ft_lstnew(nbr);
		ft_lstadd_back(stacks, tmp);
		i++;
	}
	free_array(nbrs);
}

void	initialization(int argc, char **argv, t_data *stacks)
{
	if (argc == 2)
	{
		if (ft_strlen(argv[0]) == 0)
			error_msg();
		init_string(argv, stacks);
	}
	else if (argc > 2)
		init_mult(argc, argv, stacks);
}
