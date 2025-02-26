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

static bool	check_duplicate_and_push(t_stack **stack, const char *str)
{
	t_stack	*new;
	int		value;

	if (not_integer(str) || not_within_int_range(str))
		return (true);
	value = ft_atoi(str);
	if (is_duplicate(*stack, value))
		return (true);
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
	{
		error_exit(stack, &new);
	}
	new->value = value;
	new->next = *stack;
	*stack = new;
	return (false);
}

bool	not_valid_input(int ac, char **av)
{
	int		i;
	int		j;
	char	**split;
	t_stack	*stack;

	stack = NULL;
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i]);
		if (!split || !*split)
			return (free_split(split), free_stack(&stack), true);
		j = 0;
		while (split[j])
		{
			if (check_duplicate_and_push(&stack, split[j]))
				return (free_stack(&stack), true);
			j++;
		}
		free_split(split);
		i++;
	}
	free_stack(&stack);
	return (false);
}
