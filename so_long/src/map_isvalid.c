#include "so_long.h"

static int	isborder(t_base *base, int i)
{
	if (i < base->game->width // 0 1 2 3 4
		|| i % (base->game->width + 1) == 0 // 6 12 18 24
		|| i % (base->game->width + 1) == (base->game->width - 1) // 10 16 22
		|| i > (base->game->width + 1) * (base->game->height - 1))// 25 26 27 28
		return (1);
	return (0);
}

static void	isvalid(t_base *base, char *file, int i)
{
	if (file[i] == 'P')
		base->game->count_player++;
	else if (file[i] == 'E')
		base->game->count_exit++;
	else if (file[i] == 'C')
		base->game->count_coll++;
	else if (file[i] == '1' || file[i] == '0')
		return ;
	else
	{
		free(file);
		base_destroy(base, "map content is invalid");
	}
}

void	map_isvalid(t_base *base, char *file)
{
	int				i;

	i = -1;
	while (file[++i] != 0)
	{
		if (file[i] == '\n')
			continue ;
		if (isborder(base, i))
		{
			if (file[i] != '1')
			{
				free(file);
				base_destroy(base, "map isn't surrounded by walls");
			}
		}
		else
			isvalid(base, file, i);
	}
	if (base->game->count_player != 1
		|| base->game->count_exit != 1
		|| base->game->count_coll < 1)
	{
		free(file);
		base_destroy(base, "map configuration is invalid");
	}
}
