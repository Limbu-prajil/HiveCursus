#include "so_long.h"

static void	map_width(t_base *base, char *file)
{
	base->game->width = 0;
	while (file[base->game->width] && file[base->game->width] != '\n')
		base->game->width++;
}

static void	map_height(t_base *base, char *file)
{
	int				i;
	int				j;

	base->game->height = 1;
	i = base->game->width + 1;
	while (file[i] != 0)
	{
		j = 0;
		while(file[i + j] != '\n')
			j++;
		if (base->game->width != j)
		{
			free(file);
			base_destroy(base, "map format is invalid");
		}
		i += (base->game->width + 1);
		base->game->height++;
	}
}

static void init_tmpmap(t_base *base, char *file, int **tmpmap)
{
	int i;
	int j;
	int k;

	i = -1;
	k = 0;
	while (++i < base->game->height)
	{
		tmpmap[i] = (int *)malloc(sizeof(int) * base->game->width);
		if (tmpmap[i] == 0)
		{
			free(file);
			free(tmpmap);
			base_destroy(base, "init_tmpmap(): tmpmap[]: malloc()");
		}
		j = 0;
		while (j < base->game->width)
		{
			tmpmap[i][j] = file[k];
			k++;
			j++;
		}
		k++;
	}
}

void	read_map(t_base *base, char *file)
{
	int **tmpmap;

	map_width(base, file);
	map_height(base, file);
	map_isvalid(base, file);
	base->game->coll = (t_axis *)malloc(sizeof(t_axis)
			* base->game->count_coll);
	if (base->game->coll == 0)
	{
		free(file);
		base_destroy(base, "read_map(): base.game.coll: malloc()");
	}
	base->game->map = (int **)malloc(sizeof(int *) * base->game->height);
	if (base->game->map == 0)
	{
		free(file);
		base_destroy(base, "read_map(): base.game.map: malloc()");
	}
	tmpmap = (int **)malloc(sizeof(int *) * base->game->height);
	if (tmpmap == 0)
	{
		free(file);
		base_destroy(base, "read_map(): tmpmap: malloc()");
	}
	init_tmpmap(base, file, tmpmap);
	map_init_values(base, file);
	is_solvable(base, tmpmap);
	/* if (!is_solvable(base, tmpmap))
	{
		free(file);
		free(tmpmap);
		base_destroy(base, "The map is not solvable");
	} */
}
