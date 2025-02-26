/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:47:13 by ocassany          #+#    #+#             */
/*   Updated: 2023/08/15 15:56:27 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	stacks;

	stacks.a = NULL;
	stacks.b = NULL;
	if (argc > 1)
	{
		initialization(argc, argv + 1, &stacks);
		if (check_dup(&stacks))
		{
			free_stack(stacks.a);
			error_msg();
		}
		if (!check_sorted(stacks.a))
			sort(&stacks);
		free_stack(stacks.a);
	}
	return (0);
}
