/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:18:05 by ocassany          #+#    #+#             */
/*   Updated: 2023/08/14 18:34:44 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_data *stacks, t_list *new)
{
	t_list	*tmp;

	if (!stacks->a)
	{
		stacks->a = new;
		return ;
	}
	tmp = ft_lstlast(stacks->a);
	tmp->next = new;
	new->prev = tmp;
	new->next = stacks->a;
	stacks->a->prev = new;
	return ;
}
