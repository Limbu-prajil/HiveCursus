/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:44:54 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/18 09:44:59 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void  ft_lstadd_back(t_data *stacks, t_list *new_node)
{
	t_list	*tmp;

	if (!stacks->a)
	{
		stacks->a = new_node;
		return ;
	}
	tmp = ft_lstlast(stacks->a);
	tmp->next = new_node;
	new_node->prev = tmp;
	new_node->next = stacks->a;
	stacks->a->prev = new_node;
	return ;
}
