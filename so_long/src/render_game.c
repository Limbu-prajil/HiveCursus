#include "so_long.h"

static void	texture_load(t_base *base, t_img **img, char *path)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(base->mlx, path, &width, &height);
	if (*img == 0)
		base_destroy(0, "texture_load(): can't load img");
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
