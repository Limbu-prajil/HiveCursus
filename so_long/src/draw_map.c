/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:32:28 by ashobajo          #+#    #+#             */
/*   Updated: 2024/09/21 18:45:28 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_base *base, char *file)
{
	int	i;
	int	j;
	int	k;
	int	obj;

	j = 0;
	k = 0;
	obj = 0;
	while (j < base->game->height)
	{
		base->game->map[j] = (int *)malloc(sizeof(int ) * base->game->width);
		i = 0;
		while (i < base->game->width)
		{
			get_axis(base, file, k, &obj);
			base->game->map[j][i] = file[k] - 48;
			k++;
			i++;
		}
		k++;
		j++;
	}
}
