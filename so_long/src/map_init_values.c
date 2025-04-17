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

void	map_init_values(t_base *base, char *file)
{
	int	i;
	int	j;
	int	k;
	int	obj;

	i = -1;
	k = 0;
	obj = 0;
	while (++i < base->game->height)
	{
		base->game->map[i] = (int *)malloc(sizeof(int) * base->game->width);
		if (base->game->map[i] == 0)
		{
			free(file);
			base_destroy(base, "map_init_values(): base.game.map: malloc()");
		}
		j = 0;
		while (j < base->game->width)
		{
			get_axis(base, file, k, &obj);
			base->game->map[i][j++] = file[k++] - 48;
		}
		k++;
	}
}
