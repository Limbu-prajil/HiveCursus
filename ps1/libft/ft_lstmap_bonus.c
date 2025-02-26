/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:36:45 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/10 13:56:49 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>
//t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//
//void	*toupper1(void *s)
//{
//	int i=0;
//	int len = ft_strlen((char *)s);
//	char	*p = malloc(len + 1);
//
//	ft_memcpy(p, s, len + 1);
//	while(*(p+i) != '\0')
//	{
//		*(p+i) = *(p+i)-32;
//		//printf("%c\n", *(p+i));
//		i++;
//	}
//	return ((void *)p);
//}
//
//void erase(void *s)
//{
//	char *p = s;
//	while(*p != '\0')
//	{
//		//printf("%c\n", *p);
//		*p = '\0';
//		p++;
//	}
//}
//
//int main(void)
//{
//	t_list	*lst1, *lst2;
//	//this creates char arrays on the stack, i.e., writeable memory
//	//passing string literals directly, otherwise, uses read-only memory
//	char a[] = "sit";
//	char b[] = "dalar";
//	char c[] = "ipsum";
//	char d[] = "larem";
//
//	lst1 = 0; lst2 = 0;
//	ft_lstadd_front(&lst1, ft_lstnew(a));
//	ft_lstadd_front(&lst1, ft_lstnew(b));
//	ft_lstadd_front(&lst1, ft_lstnew(c));
//	ft_lstadd_front(&lst1, ft_lstnew(d));
//	lst2 = ft_lstmap(lst1, &toupper1, &free);
//	while(lst2)
//	{
//		printf("%s\n", lst2->content);
//		lst2 = lst2->next;
//	}
//	return (0);
//}
//
//this was my first interpretation of what lstmap should do:
//delete the original list after the mapping is complete
//t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
//{
//	t_list	*lstmap;
//	t_list	*tmp;
//	t_list 	*new;
//
//	lstmap = 0;
//	while (lst)
//	{
//		//printf("a\n");
//		//printf("%s\n", lst->content);
//
//		//printf("%s\n", (char *)mod);
//		ft_lstadd_back(&lstmap, ft_lstnew(f(lst->content)));
//		tmp = lst->next;
//		ft_lstdelone(lst, del);
//		lst = tmp;
//		//printf("%s\n", lst->content);
//		//printf("test\n");
//	}
//
//	return (lstmap);
//}
//the following function works and is more time-efficient because
//the mapped list is not traversed every time a new node is added;
//it is, unfortunately, too long though
//t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
//{
//	t_list	*lstmap;
//	t_list	*iter;
//	t_list	*node;
//	void	*y;
//
//	lstmap = 0;
//	iter = 0;
//	while (lst)
//	{
//
//		y = f(lst->content);
//		node = ft_lstnew(y);
//		if (!node)
//		{
//			free(y);
//			ft_lstclear(&lstmap, del);
//			break ;
//		}
//		if(iter == 0)
//		{
//			lstmap = node;
//			iter = node;
//		}
//		else
//		{
//			iter->next = node;
//			iter = node;
//		}
//		lst = lst->next;
//	}
//	return (lstmap);
//}
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstmap;
	t_list	*node;
	void	*y;

	lstmap = 0;
	while (lst)
	{
		y = f(lst->content);
		node = ft_lstnew(y);
		if (!node)
		{
			free(y);
			ft_lstclear(&lstmap, del);
			break ;
		}
		ft_lstadd_back(&lstmap, node);
		lst = lst->next;
	}
	return (lstmap);
}
