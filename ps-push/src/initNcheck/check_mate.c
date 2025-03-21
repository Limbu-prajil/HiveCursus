/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:27:39 by plimbu            #+#    #+#             */
/*   Updated: 2025/03/21 14:27:42 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_list	*tmp;
	t_list	*tmp2;

	tmp = stacks->a;
	while (tmp->next != stacks->a)
	{
		tmp2 = tmp->next;
		while (tmp2 != stacks->a)
		{
			if (tmp->nbr == tmp2->nbr)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	tmp2 = tmp->next;
	while (tmp2 != stacks->a)
	{
		if (tmp->nbr == tmp2->nbr)
			return (1);
		tmp2 = tmp2->next;
	}
	return (0);
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
				j++;
			else if ((str[i][j] == '-' && !ft_isdigit(str[i][j + 1])))
				return (1);
			if (!ft_isdigit(str[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
