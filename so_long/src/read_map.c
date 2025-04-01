/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:24:34 by ashobajo          #+#    #+#             */
/*   Updated: 2024/09/21 18:46:10 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_width(t_base *base, char *file)
{
	base->game->width = 0;
	while (file[base->game->width] && file[base->game->width] != '\n')
		base->game->width++;
}

void	map_height(t_base *base, char *file)
{
	int				i;
	int				j;

	base->game->height = 1;
	i = base->game->width + 1;
	while (file[i] != 0)
	{
		j = 0;
		while (file[i + j] != 0 && file[i + j] != '\n')
			j++;
		if (base->game->width != j)
		{
			free(file);
			base_destroy(base, "map format is invalid", 0);
		}
		i += base->game->width + 1;
		base->game->height++;
	}
}

void	read_map(t_base *base, char *file)
{
	map_width(base, file);
	map_height(base, file);
	map_isvalid(base, file);
	base->game->coll = (t_axis *)malloc(sizeof(t_axis)
			* base->game->count_coll);
	if (base->game->coll == 0)
	{
		free(file);
		base_destroy(base, "base_parsing(): malloc()", errno);
	}
	base->game->map = (int **)malloc(sizeof(int *) * base->game->height);
	if (base->game->map == 0)
	{
		free(file);
		base_destroy(base, "map_parsing(): malloc()", errno);
	}
	draw_map(base, file);
}
