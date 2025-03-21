/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack_or_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:11:39 by plimbu            #+#    #+#             */
/*   Updated: 2025/03/21 15:11:41 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
