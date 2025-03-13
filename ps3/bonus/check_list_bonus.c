/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <ulayus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:22:06 by ulayus            #+#    #+#             */
/*   Updated: 2023/01/05 18:22:57 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

void	ft_exit(void *elem, int flag)
{
	t_list	*tmp;

	if (flag == DOUBLE || flag == SORTED)
	{
		while (((t_list *)elem))
		{
			tmp = ((t_list *)elem);
			elem = ((t_list *)elem)->next;
			free(tmp);
		}
	}
	else if (flag == NOT_NB || flag == INVALID)
		free(elem);
	if (flag != SORTED)
		ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	isdouble(t_list *head)
{
	t_list	*tmp;

	while (head->next)
	{
		tmp = head->next;
		while (tmp)
		{
			if (tmp->nb == head->nb)
				return (1);
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (0);
}

int	issorted(t_list *head)
{
	while (head->next)
	{
		if (head->nb > head->next->nb)
			return (0);
		head = head->next;
	}
	return (1);
}
