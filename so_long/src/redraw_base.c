/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:54:14 by ashobajo          #+#    #+#             */
/*   Updated: 2024/09/21 18:46:45 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_move(t_base *base, int x, int y)
{
	if (base->game->player.x != x || base->game->player.y != y)
	{
		base->game->player_move++;
		ft_putnbr_fd(base->game->player_move, 1);
		ft_putendl_fd("", 1);
	}
}

static void	iscollectable(t_base *base)
{
	int				k;

	k = 0;
	while (k < base->game->count_coll)
	{
		if (base->game->coll[k].x == base->game->player.x
			&& base->game->coll[k].y == base->game->player.y)
		{
			base->game->coll[k].x = -1;
			base->game->coll[k].y = -1;
			base->game->player_coll++;
		}
		k++;
	}
}

void	redraw_base(t_base *base)
{
	int				x;
	int				y;

	x = base->game->player.x;
	y = base->game->player.y;
	if (base->game->player_up != 0)
		move_up(base, x, y);
	else if (base->game->player_down != 0)
		move_down(base, x, y);
	else if (base->game->player_left != 0)
		move_left(base, x, y);
	else if (base->game->player_right != 0)
		move_right(base, x, y);
	print_move(base, x, y);
	iscollectable(base);
	create_base(base);
	if (base->game->exit.x == base->game->player.x
		&& base->game->exit.y == base->game->player.y)
		if (base->game->count_coll == base->game->player_coll)
			base_destroy(base, 0, 0);
}
