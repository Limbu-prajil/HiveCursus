NAME	=	so_long
CC		=	cc
FLAGS	=	-Wall -Wextra -Werror
MLX		=	mlx/Makefile.gen
LFT		=	libft/libft.a
INC		=	-I ./inc -I ./libft -I ./mlx
LIB		=	-L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd
OBJ		=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC		=	src/base_destroy.c \
			src/base_init.c \
			src/create_base.c \
			src/die.c \
			src/draw_map.c \
			src/game_destroy.c \
			src/game_hook.c \
			src/game_init.c \
			src/get_axis.c \
			src/map_init.c \
			src/map_isvalid.c \
			src/pixels.c \
			src/player_movement.c\
			src/read_map.c \
			src/redraw_base.c \
			src/render_game.c \
			src/so_long.c

all:	$(MLX) $(LFT) obj $(NAME)

$(NAME):$(OBJ)
		$(CC) $(FLAGS) -fsanitize=address -o $@ $^ $(LIB)

$(MLX):
		@echo "Compiling minilibx..."
		@make -s -C mlx
		@echo "Minilibx ready!"

$(LFT):
		@echo "Compiling libft..."
		@make -s -C libft
		@echo "Libft ready!"

obj:
		@mkdir -p obj

obj/%.o:src/%.c
		$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
		@rm -rf $(OBJ) obj

fclean:	clean
		@make -s $< -C libft
		@echo "libft obj removed."
		@make -s $< -C mlx
		@echo "minilibx obj removed."
		@rm -rf $(LFT)
		@echo "libft archive removed."
		@rm -rf $(MLX)
		@echo "minilibx Makefile.gen removed."
		@rm -rf $(NAME)
		@echo "binary so_long file removed."

re:		fclean all

.PHONY:	all clean fclean re
