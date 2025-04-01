/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:35:43 by gamarcha          #+#    #+#             */
/*   Updated: 2024/09/21 12:35:53 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>
# include <mlx_int.h>
# include "libft.h"

typedef struct s_axis
{
	int				x;
	int				y;
}				t_axis;

typedef struct s_game
{
	int				**map;
	int				height;
	int				width;
	t_axis			player;
	int				player_up;
	int				player_down;
	int				player_left;
	int				player_right;
	int				player_move;
	int				player_coll;
	t_axis			exit;
	t_axis			*coll;
	int				count_coll;
	int				count_exit;
	int				count_player;
}				t_game;

typedef struct s_base
{
	void			*mlx;
	void			*mlx_win;
	t_img			*mlx_img;
	t_game			*game;
	t_img			*player;
	t_img			*exit;
	t_img			*coll;
	t_img			*wall;
	t_img			*ground;
}				t_base;

void map_init(t_base *base, char *filename);
t_base *base_init(char *filename);
void game_init(t_base *base, char *filename);
void read_map(t_base *base, char *file);
void get_axis(t_base *base, char *file, int k, int * obj);
void draw_map(t_base *base, char *file);
void render_game(t_base *base);
void	base_destroy(t_base *base, char *errmsg, int errnum);
void	game_destroy(t_game *game);
void	create_base(t_base *base);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);
void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
unsigned int	mlx_get_pixel(t_img *img, int x, int y);
void	map_isvalid(t_base *base, char *file);
void	die(char *errmsg, int errnum);
// static void	texture_load(t_base *base, t_img **img, char *path);
int	isber(char *file);
// static void	file_parse(t_base *base, char **file, char buf[], int fd);
// static void	file_read(t_base *base, char **file, char buf[], int fd);
// static char	*file_init(t_base *base, int fd);
void	map_init(t_base *base, char *filename);


//hooks: Press, Release, destory game
int key_press(int key_code, t_base *base);
int	key_release(int key_code, t_base *base);
int destroy_game(int key_code, t_base *base);

// Player_Movement
void	move_up(t_base *base, int x, int y);
void	move_down(t_base *base, int x, int y);
void	move_left(t_base *base, int x, int y);
void	move_right(t_base *base, int x, int y);

// Redraw base after every movement
void	redraw_base(t_base *base);

#endif
