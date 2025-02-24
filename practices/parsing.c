/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:11:39 by plimbu            #+#    #+#             */
/*   Updated: 2025/02/24 16:11:46 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

bool	not_integer(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (true);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	not_within_int_range(const char *str)
{
	long	num;

	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (true);
	return (false);
}

bool	is_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (true);
		stack = stack->next;
	}
	return (false);
}

bool	not_valid_input(int ac, char **av)
{
	int		i;
	int		j;
	char	**split;
	t_stack	*stack;
	t_stack	*new;

	stack = NULL;
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i]);
		if (!split[0])
			return (true);
		j = 0;
		while (split[j])
		{
			if (not_integer(split[j]) || not_within_int_range(split[j]))
			{
				free_stack(&stack);
				return (true);
			}
			if (is_duplicate(stack, ft_atoi(split[j])))
			{
				free_stack(&stack);
				return (true);
			}
			new = (t_stack *)malloc(sizeof(t_stack));
			if (!new)
			{
				free_stack(&stack);
				return (true);
			}
			new->value = ft_atoi(split[j]);
			new->next = stack;
			stack = new;
			j++;
		}
		i++;
	}
	free_stack(&stack);
	return (false);
}
