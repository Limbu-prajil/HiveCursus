/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:45:32 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/18 09:45:36 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_stack **lst, int (del)(int))
{
	t_stack	*start;
	t_stack	*temp;

	if (!lst || !del)
		return ;
	start = *lst;
	temp = NULL;
	while (start)
	{
		temp = start;
		start = start->next;
		del(temp->value);
		free(temp);
	}
	*lst = NULL;
}
