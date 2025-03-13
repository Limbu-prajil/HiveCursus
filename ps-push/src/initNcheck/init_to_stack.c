#include "../../inc/push_swap.h"

void	multi_init(int argc, char **argv, t_data *stacks)
{
	int		i;
	t_list	*tmp;

	if (!digits(argv))
		error_msg(NULL, NULL);
	i = 0;
	while (i < argc - 1)
	{
		tmp = ft_lstnew(ft_atol(argv[i]));
		ft_lstadd_back(stacks, tmp);
		if (stacks->a->nbr > INT_MAX || stacks->a->nbr < INT_MIN)
			error_msg(NULL, stacks->a);
		i++;
	}
}

void	str_init(char **argv, t_data *stacks)
{
	char	**nbrs;
	int		i;
	long long	nbr;		
	t_list	*tmp;

	nbrs = ft_split_del((char const *)argv[0], ' ');
	if (nbrs == NULL || nbrs[0] == NULL)
		error_msg(nbrs, NULL);
	if (!digits(nbrs))
		error_msg(nbrs, NULL);
	i = 0;
	while (nbrs[i])
	{
		nbr = ft_atol(nbrs[i++]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			error_msg(nbrs, stacks->a);
		tmp = ft_lstnew(nbr);
		ft_lstadd_back(stacks, tmp);
	}
	free_array(nbrs);
}

void	start_init(int argc, char **argv, t_data *stacks)
{
	if (argc == 2)
	{
		if (ft_strlen(argv[0]) == 0)
			error_msg(NULL, NULL);
		str_init(argv, stacks);
	}
	else if (argc > 2)
		multi_init(argc, argv, stacks);
}
