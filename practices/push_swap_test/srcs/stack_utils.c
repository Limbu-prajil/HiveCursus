/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:11:57 by plimbu            #+#    #+#             */
/*   Updated: 2025/02/24 16:12:00 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	error_exit(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	process_split(char **split, t_stack **a)
{
	t_stack	*new_node;
	int		len;

	len = 0;
	while (split[len])
		len++;
	while (len > 0)
	{
		new_node = ft_lstnew(ft_atoi(split[len - 1]));
		if (!new_node)
		{
			free_split(split);
			error_exit(a, &new_node);
		}
		ft_lstadd_front(a, new_node);
		len--;
	}
}

t_stack	*create_stack(int ac, char **av)
{
	t_stack	*a;
	char	**split;
	int		i;

	a = NULL;
	i = ac - 1;
	while (i > 0)
	{
		split = ft_split(av[i]);
		if (!split || !*split)
		{
			free_split(split);
			error_exit(&a, NULL);
		}
		process_split(split, &a);
		free_split(split);
		i--;
	}
	return (a);
}
