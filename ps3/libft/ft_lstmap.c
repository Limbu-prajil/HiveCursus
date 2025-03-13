/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:21:25 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/28 13:42:05 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstmap(t_lst *lst, void *(*f)(void *), void (*del)(void *))
{
	t_lst	*new;
	t_lst	*begin;

	if (!lst || !f)
		return (0);
	new = ft_calloc(1, sizeof(t_lst));
	begin = new;
	while (lst)
	{
		new->next = ft_calloc(1, sizeof(t_lst));
		if (!new->next)
		{
			ft_lstclear(&begin, del);
			return (0);
		}
		new->content = f(lst->content);
		lst = lst->next;
		new = new->next;
	}
	return (begin);
}
