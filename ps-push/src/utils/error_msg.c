/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:11:00 by plimbu            #+#    #+#             */
/*   Updated: 2025/03/21 15:11:03 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	error_msg(char **arr, t_list *stack)
{
	if (arr)
		free_array(arr);
	if (stack)
		free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}
