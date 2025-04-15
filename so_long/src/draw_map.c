#include "so_long.h"

void	draw_map(t_base *base, char *file)
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
			base_destroy(base, "draw_map(): malloc()", errno);
		}
		j = 0;
		while (j < base->game->width)
		{
			get_axis(base, file, k, &obj);
			base->game->map[i][j++] = file[k] - 48;
			k++;
		}
		k++;
	}
}
