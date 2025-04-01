/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:15:11 by ashobajo          #+#    #+#             */
/*   Updated: 2024/09/21 18:45:01 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_base	*base_init(char *filename)
{
	t_base	*base;

	base = (t_base *)malloc(sizeof(t_base));
	if (base == 0)
		base_destroy(0, "base_init(): malloc()", errno);
	base->game = 0;
	base->mlx = 0;
	base->mlx_win = 0;
	base->mlx_img = 0;
	base->player = 0;
	base->exit = 0;
	base->coll = 0;
	base->wall = 0;
	base->ground = 0;
	game_init(base, filename);
	render_game(base);
	return (base);
}
