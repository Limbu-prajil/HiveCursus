/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:29:14 by ashobajo          #+#    #+#             */
/*   Updated: 2024/09/21 18:41:47 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	base_destroy(t_base *base, char *errmsg, int errnum)
{
	if (base != 0)
	{
		if (base->ground != 0)
			mlx_destroy_image(base->mlx, base->ground);
		if (base->wall != 0)
			mlx_destroy_image(base->mlx, base->wall);
		if (base->coll != 0)
			mlx_destroy_image(base->mlx, base->coll);
		if (base->exit != 0)
			mlx_destroy_image(base->mlx, base->exit);
		if (base->player != 0)
			mlx_destroy_image(base->mlx, base->player);
		if (base->mlx_img != 0)
			mlx_destroy_image(base->mlx, base->mlx_img);
		if (base->mlx_win != 0)
			mlx_destroy_window(base->mlx, base->mlx_win);
		if (base->mlx != 0)
			mlx_destroy_display(base->mlx);
		if (base->game != 0)
			game_destroy(base->game);
		free(base);
	}
	die(errmsg, errnum);
}
