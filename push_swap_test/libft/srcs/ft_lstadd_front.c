/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:45:17 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/18 09:45:22 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new_node)
{
	new_node->next = *lst;
	if (*lst)
		(*lst)->prev = new_node;
	*lst = new_node;
}
