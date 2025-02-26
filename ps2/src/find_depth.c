/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_depth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:26:06 by ocassany          #+#    #+#             */
/*   Updated: 2023/08/13 17:02:44 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_depth(t_list *stack, int nbr)
{
	t_list	*tmp;
	int		d;

	tmp = stack;
	d = 0;
	while (tmp->next != stack)
	{
		if (tmp->nbr == nbr)
			return (d);
		d++;
		tmp = tmp->next;
	}
	return (d);
}
