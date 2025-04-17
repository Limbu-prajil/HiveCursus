#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <mlx_int.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include <stdio.h>

typedef struct s_axis
{
	int			x;
	int			y;
}				t_axis;

typedef struct s_game
{
	t_axis		player;
	t_axis		exit;
	t_axis		*coll;
	int			height;
	int			width;
	int			**map;
	int			player_up;
	int			player_down;
	int			player_left;
	int			player_right;
	int			player_move;
	int			player_coll;
	int			count_coll;
	int			count_exit;
	int			count_player;
}				t_game;

typedef struct s_base
{
	t_game		*game;
	void		*mlx;
	void		*mlx_win;
	t_img		*mlx_img;
	t_img		*player;
	t_img		*exit;
	t_img		*coll;
	t_img		*wall;
	t_img		*ground;
}				t_base;

t_base			*base_init(char *filename);
void			game_init(t_base *base, char *filename);
void			map_init(t_base *base, char *filename);
void			read_map(t_base *base, char *file);
void			map_isvalid(t_base *base, char *file);
void			get_axis(t_base *base, char *file, int k, int *obj);
void			map_init_values(t_base *base, char *file);
int				is_solvable(t_base *base, int **tmpmap);
void			render_game(t_base *base);

void			create_base(t_base *base);
unsigned int	get_pixel(t_img *img, int x, int y);
unsigned int	rgb_to_int(int o, int r, int g, int b);
void			draw_pixel(t_img *mlx_img, int x, int y, int color);


// destroy stuff
void			base_destroy(t_base *base, char *errmsg);
void			game_destroy(t_game *game);
void			error(char *errmsg);

//hooks
int				key_press(int key_code, t_base *base);
int				key_release(int key_code, t_base *base);
int				destroy_game(int key_code, t_base *base);

// movements
void			move_up(t_base *base, int x, int y);
void			move_down(t_base *base, int x, int y);
void			move_left(t_base *base, int x, int y);
void			move_right(t_base *base, int x, int y);

// move and redraw
void			redraw_base(t_base *base);

#endif
