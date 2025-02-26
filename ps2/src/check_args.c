/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:38:58 by ocassany          #+#    #+#             */
/*   Updated: 2023/08/13 16:59:10 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_sorted(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_dup(t_data *stacks)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = stacks->a;
	while (tmp->next != stacks->a)
	{
		tmp2 = tmp;
		while (tmp2->next != stacks->a)
		{
			if (tmp2->nbr == tmp2->next->nbr)
				return (1);
			tmp2 = tmp2->next;
		}
		if (tmp2->nbr == tmp2->next->nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_asciinbr(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] == '-' && ft_isdigit(str[i][j + 1]))
				|| (str[i][j] == ' ' && (ft_isdigit(str[i][j + 1]))))
				j++;
			else if (str[i][j] == ' ' && str[i][j + 1] == '-')
				j += 2;
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
