#include "so_long.h"

static void	draw_square(t_base *base, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = -1;
	while (++j < 40)
	{
		i = -1;
		while (++i < 40)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(base->mlx_img, x + i, y + j, color);
		}
	}
}

static void	draw_env(t_base *base, int i, int j)
{
	int				k;

	if (base->game->exit.x == i && base->game->exit.y == j)
		draw_square(base, base->exit, i * 40, j * 40);
	k = -1;
	while (++k < base->game->count_coll)
	{
		if (base->game->coll[k].x == i && base->game->coll[k].y == j)
			draw_square(base, base->coll, i * 40, j * 40);
	}
	if (base->game->player.x == i && base->game->player.y == j)
		draw_square(base, base->player, i * 40, j * 40);
}

static void	draw_game_elements(t_base *base)
{
	int				i;
	int				j;

	j = -1;
	while (++j < base->game->height)
	{
		i = -1;
		while (++i < base->game->width)
		{
			if (base->game->map[j][i] == 1)
				draw_square(base, base->wall, i * 40, j * 40);
			else
				draw_square(base, base->ground, i * 40, j * 40);
			draw_env(base, i, j);
		}
	}
}

void	create_base(t_base *base)
{
	draw_game_elements(base);
	mlx_put_image_to_window(base->mlx, base->mlx_win, base->mlx_img, 0, 0);
}
