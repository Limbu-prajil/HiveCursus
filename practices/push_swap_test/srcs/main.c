/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:11:22 by plimbu            #+#    #+#             */
/*   Updated: 2025/02/24 16:11:27 by plimbu           ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	if (not_valid_input(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = create_stack(ac, av);
	b = NULL;
	if (is_sorted(a))
	{
		ft_printf("Stack is already sorted.\n");
		free_stack(&a);
		return (0);
	}
	print_stack(a, "Stack A (Initial)");
	push_swap(&a, &b);
	print_stack(a, "Stack A (Sorted)");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
