#include "so_long.h"

int	key_press(int key_code, t_base *base)
{
	if (key_code == 65307)
		base_destroy(base, 0);
	if (key_code == 119 || key_code == 65362)
		base->game->player_up = 1;
	if (key_code == 115 || key_code == 65364)
		base->game->player_down = 1;
	if (key_code == 97 || key_code == 65361)
		base->game->player_left = 1;
	if (key_code == 100 || key_code == 65363)
		base->game->player_right = 1;
	redraw_base(base);
	return (0);
}

int	key_release(int key_code, t_base *base)
{
	if (key_code == 119 || key_code == 65362)
		base->game->player_up = 0;
	if (key_code == 115 || key_code == 65364)
		base->game->player_down = 0;
	if (key_code == 97 	|| key_code == 65361)
		base->game->player_left = 0;
	if (key_code == 100 || key_code == 65363)
		base->game->player_right = 0;
	redraw_base(base);
	return (0);
}

int	destroy_game(int key_code, t_base *base)
{
	(void)key_code;
	(void)base;
	base_destroy(0, 0);
	return (0);
}
