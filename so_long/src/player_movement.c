/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:50:08 by ashobajo          #+#    #+#             */
/*   Updated: 2024/09/21 18:44:23 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_base *base, int x, int y)
{
	if (base->game->map[y - 1][x] == 0)
		base->game->player.y -= 1;
}

void	move_down(t_base *base, int x, int y)
{
	if (base->game->map[y + 1][x] == 0)
		base->game->player.y += 1;
}

void	move_left(t_base *base, int x, int y)
{
	if (base->game->map[y][x - 1] == 0)
		base->game->player.x -= 1;
}

void	move_right(t_base *base, int x, int y)
{
	if (base->game->map[y][x + 1] == 0)
		base->game->player.x += 1;
}
