/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:25:16 by ashobajo          #+#    #+#             */
/*   Updated: 2024/09/21 18:50:39 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	texture_load(t_base *base, t_img **img, char *path)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(base->mlx, path, &width, &height);
	if (*img == 0)
		base_destroy(0, "texture_init(): can't load texture", 0);
	(*img)->width = width;
	(*img)->height = height;
}

void	render_game(t_base *base)
{
	base->mlx = mlx_init();
	base->mlx_win = mlx_new_window(base->mlx, base->game->width
			* 40, base->game->height * 40, "So_Long!");
	base->mlx_img = mlx_new_image(base->mlx, base->game->width
			* 40, base->game->height * 40);
	texture_load(base, &base->player, "./img/player.xpm");
	texture_load(base, &base->exit, "./img/helicopter.xpm");
	texture_load(base, &base->coll, "./img/gas.xpm");
	texture_load(base, &base->wall, "./img/wall.xpm");
	texture_load(base, &base->ground, "./img/sand.xpm");
}

// void render_game(t_base *base)
// {
// 	int width, height;

// 	base->mlx = mlx_init();
// 	base->mlx_win = mlx_new_window(base->mlx, base->game->width 
		//* 40, base->game->height *40, "So_Long!");
// 	base->mlx_img = mlx_new_image(base->mlx, base->game->width 
//		* 40, base->game->height *40);

// 	base->player = mlx_xpm_file_to_image
	//	(base->mlx, "./img/player.xpm", &width, &height);
// 	if (base->player == 0)
// 		base_destroy(0, "texture_init(): can't load player texture", 0);
// 	base->player->width = width;
// 	base->player->height = height;

// 	base->exit = mlx_xpm_file_to_image
		//(base->mlx, "./img/helicopter.xpm", &width, &height);
// 	if (base->exit == 0)
// 		base_destroy(0, "texture_init(): can't load exit texture", 0);
// 	base->exit->width = width;
// 	base->exit->height = height;

// 	base->coll = mlx_xpm_file_to_image
		//(base->mlx, "./img/gas.xpm", &width, &height);
// 	if (base->coll == 0)
// 		base_destroy(0, "texture_init(): can't load collectible texture", 0);
// 	base->coll->width = width;
// 	base->coll->height = height;

// 	base->wall = mlx_xpm_file_to_image
		//(base->mlx, "./img/wall.xpm", &width, &height);
// 	if (base->wall == 0)
// 		base_destroy(0, "texture_init(): can't load wall texture", 0);
// 	base->wall->width = width;
// 	base->wall->height = height;

// 	base->ground = mlx_xpm_file_to_image
		//(base->mlx, "./img/sand.xpm", &width, &height);
// 	if (base->ground == 0)
// 		base_destroy(0, "texture_init(): can't load ground texture", 0);
// 	base->ground->width = width;
// 	base->ground->height = height;
// }
