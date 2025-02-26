/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:42:13 by ocassany          #+#    #+#             */
/*   Updated: 2023/08/15 14:53:41 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_list *stack)
{
	t_list	*tmp;
	t_list	*head;

	if (!stack)
		return ;
	head = stack;
	while (stack->next != head)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	free(stack);
}
