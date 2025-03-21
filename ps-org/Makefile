NAME = push_swap

SRCS = src/main.c \
	src/initNcheck/check_mate.c \
	src/initNcheck/init_to_stack.c \
	src/sort/turk_sort.c \
	src/sort/opti_ops_to_stack.c \
	src/sort/best_opsnum.c \
	src/sort/best_ops_to_exec.c \
	src/utils/find_best_depth_in_a.c \
	src/utils/find_max_or_min.c \
	src/utils/free_stack_or_array.c \
	src/utils/error_msg.c \
	src/ops/push.c \
	src/ops/swap.c \
	src/ops/rotate.c \
	src/ops/rev-rot.c \

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
	@echo "Push_Swap sucksesfooli created!"

clean :
	@$(RM) $(OBJS)
	@make clean -C $(LIB)
	@echo "All objects sucksesfooli cleaned!"

fclean : clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB)
	@echo "Archives and Execs sucksesfooli Fcleaned!"

re : fclean all

.PHONY = all clean fclean re
