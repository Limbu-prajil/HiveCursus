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

void	print_stack(t_stack *stack, char *name)
{
	ft_printf("%s: ", name);
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
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
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

t_stack	*create_stack(int ac, char **av)
{
	t_stack	*a;
	t_stack	*new_node;
	int		i;
	int		len;
	char	**split;

	a = NULL;
	i = ac - 1;
	while (i > 0)
	{
		split = ft_split(av[i]);
		if (!split)
			error_exit(&a, NULL);
		len = 0;
		while (split[len])
			len++;
		while (len > 0)
		{
			new_node = ft_lstnew(ft_atoi(split[len - 1]));
			if (!new_node)
				error_exit(&a, NULL);
			ft_lstadd_front(&a, new_node);
			len--;
		}
		i--;
	}
	return (a);
}
