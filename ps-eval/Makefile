NAME = push_swap

SRCS = src/main.c \
	src/initNcheck/check_args.c \
	src/initNcheck/initialization.c \
	src/ops/calcs.c \
	src/ops/execs.c \
	src/ops/push.c \
	src/ops/swap.c \
	src/ops/rotate.c \
	src/ops/rev-rot.c \
	src/sort/sort.c \
	src/sort/sort2.c \
	src/utils/find_max.c \
	src/utils/find_min.c \
	src/utils/find_depth.c \
	src/utils/find_best.c \
	src/utils/free_stack.c \
	src/utils/free_array.c \
	src/utils/error_msg.c \
	src/utils/ft_printf.c

OBJS = $(SRCS:.c=.o)

CC = cc

LIB = inc/libft/

CFLAGS = -Wall -Wextra -Werror -I$(LIB)

RM = rm -rf

all : $(NAME)

$(LIB)libft.a:
	@make -C $(LIB)

$(NAME) : $(OBJS) $(LIB)libft.a
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIB) -lft -o $(NAME)
	@echo "push_swap sucksesfooli created!"

clean :
	@$(RM) $(OBJS)
	@make clean -C $(LIB)
	@echo "all objects sucksesfooli cleaned!"

fclean : clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB)
	@echo "archives and execs sucksesfooli Fcleaned!"

re : fclean all

.PHONY = all clean fclean re
