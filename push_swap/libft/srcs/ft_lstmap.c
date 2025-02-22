/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:46:41 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/18 09:46:51 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lsapply(t_stack *l, t_stack *s, int (f)(int), int (d)(int))
{
	if (l)
	{
		s = ft_lstnew(f(l->value));
		if (!s)
		{
			ft_lstclear(&s, d);
			return (NULL);
		}
		s->next = ft_lsapply(l->next, s->next, f, d);
	}
	return (s);
}

t_stack	*ft_lstmap(t_stack *lst, int (f)(int), int (del)(int))
{
	t_stack	*start;

	start = NULL;
	start = ft_lsapply(lst, start, f, del);
	return (start);
}
