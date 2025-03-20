#include "../../inc/push_swap.h"

int	not_sorted(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	duplicates(t_data *stacks)
{
    t_list *tmp;
    t_list *tmp2;

    tmp = stacks->a;
    while (tmp->next != stacks->a) // Outer loop to traverse the list
    {
        tmp2 = tmp->next;
        while (tmp2 != stacks->a) // Inner loop to check for duplicates
        {
            if (tmp->nbr == tmp2->nbr) // Check for duplicate
                return 1;
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }

    // Check the last node against the first node
    tmp2 = tmp->next;
    while (tmp2 != stacks->a)
    {
        if (tmp->nbr == tmp2->nbr)
            return 1;
        tmp2 = tmp2->next;
    }
    return 0;
}

int	not_digits(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] == '-' && ft_isdigit(str[i][j + 1])))
			if (!ft_isdigit(str[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
