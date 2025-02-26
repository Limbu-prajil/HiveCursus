/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudloff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:42:15 by mrudloff          #+#    #+#             */
/*   Updated: 2022/10/27 11:42:20 by mrudloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newl;
	t_list	*setnl;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	newl = ft_lstnew(f(lst->content));
	if (!newl)
		return (NULL);
	setnl = newl;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&newl, del);
			return (NULL);
		}
		setnl->next = tmp;
		setnl = tmp;
		lst = lst->next;
	}
	return (newl);
}
