/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:29:34 by ulayus            #+#    #+#             */
/*   Updated: 2023/01/06 17:24:47 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

int	main(int ac, char **av)
{
	t_list	*head_a;
	t_list	*head_b;
	int		i;

	head_a = NULL;
	head_b = NULL;
	if (ac < 2)
		return (0);
	head_a = create_list(ac, av);
	if (head_a == NULL)
		return (0);
	if (isdouble(head_a))
		ft_exit(head_a, DOUBLE);
	add_index(&head_a);
	apply_instructions(&head_a, &head_b);
	i = 0;
	if (issorted(head_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(head_a, head_b);
	return (0);
}
