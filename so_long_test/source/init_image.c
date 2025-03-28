/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:03:36 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/05 18:54:52 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	calculate_image_size(t_game *game)
{
	game->image_size.x = game->map->window_w / game->map->cols;
	game->image_size.y = game->map->window_h / game->map->rows;
	if (game->image_size.x <= game->image_size.y)
		game->render_pixel = game->image_size.x;
	else
		game->render_pixel = game->image_size.y;
	if (game->render_pixel < 1)
	{
		game->render_pixel = 1;
	}
}

static mlx_image_t	*png_to_image(t_game *game, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
		exit_game(game, mlx_strerror(mlx_errno), EXIT_FAILURE);
	img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	if (!img)
		exit_game(game, mlx_strerror(mlx_errno), EXIT_FAILURE);
	if (!mlx_resize_image(img, game->render_pixel, game->render_pixel))
		exit_game(game, mlx_strerror(mlx_errno), EXIT_FAILURE);
	return (img);
}

void	image_init(t_game *game)
{
	calculate_image_size(game);
	game->image = ft_calloc(PNG_NUM, sizeof(mlx_image_t));
	if (!game->image)
		exit_game(game, "Memory allocation for image(s) failed!", EXIT_FAILURE);
	game->image[R] = png_to_image(game, PLAYER_RIGHT);
	game->image[L] = png_to_image(game, PLAYER_LEFT);
	game->image[U] = png_to_image(game, PLAYER_UP);
	game->image[D] = png_to_image(game, PLAYER_DOWN);
	game->image[C] = png_to_image(game, COLLECTIBLE);
	game->image[E] = png_to_image(game, EXIT_PATH_CLOSE);
	game->image[O] = png_to_image(game, EXIT_PATH_OPEN);
	game->image[S] = png_to_image(game, SPACE);
	game->image[W] = png_to_image(game, WALL);
}
