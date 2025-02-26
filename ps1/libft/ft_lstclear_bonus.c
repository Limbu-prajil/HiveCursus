/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:19:10 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/04 08:44:09 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*iter;
	t_list	*tmp;

	if (*lst)
	{
		iter = *lst;
		while (iter->next)
		{
			del(iter->content);
			tmp = iter->next;
			free(iter);
			iter = tmp;
		}
		del(iter->content);
		free(iter);
		*lst = 0;
	}
}
