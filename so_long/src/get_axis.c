/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_axis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:32:55 by ashobajo          #+#    #+#             */
/*   Updated: 2024/09/21 18:44:47 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_axis(t_base *base, char *file, int k, int *obj)
{
	if (file[k] == 'P')
	{
		base->game->player.x = k % (base->game->width + 1);
		base->game->player.y = k / (base->game->width + 1);
		file[k] = '0';
	}
	if (file[k] == 'E')
	{
		base->game->exit.x = k % (base->game->width + 1);
		base->game->exit.y = k / (base->game->width + 1);
		file[k] = '0';
	}
	if (file[k] == 'C')
	{
		base->game->coll[*obj].x = k % (base->game->width + 1);
		base->game->coll[*obj].y = k / (base->game->width + 1);
		file[k] = '0';
		(*obj)++;
	}
}
