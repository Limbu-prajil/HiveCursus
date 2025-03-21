/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:28:22 by plimbu            #+#    #+#             */
/*   Updated: 2025/03/21 14:28:25 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	printstack(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (tmp->next != a)
	{
		ft_printf("%d ", tmp->nbr);
		tmp = tmp->next;
	}
	ft_printf("%d", tmp->nbr);
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_data	stacks;

	stacks.a = NULL;
	stacks.b = NULL;
	if (argc > 1)
	{
		start_init(argc, argv + 1, &stacks);
		if (duplicates(&stacks))
			error_msg(NULL, stacks.a);
		if (not_sorted(stacks.a))
		{
			turk_sort(&stacks);
		}
		free_stack(stacks.a);
	}
	return (0);
}
