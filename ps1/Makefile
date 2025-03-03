NAME = push_swap
OBJ_DIR = obj

SRCS = main.c \
	init_stack.c \
	do_push.c \
	do_sort3.c \
	get_index_dest.c \
	get_index_min.c \
	push.c \
	rerot.c \
	rot.c \
	sort.c \
	swap.c \
	whatif_push_ab.c \

OBJS = $(SRCS:%.c=%.o)

CC = cc

LIB = libft

CFLAGS = -Wall -Wextra -Werror -I$(LIB)

RM = rm -rf

all : $(NAME)

$(LIB)/libft.a:
	@make -C $(LIB)

$(OBJ_DIR)/%.o: $(SRCS)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(LIB)/libft.a
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIB) -lft -o $(NAME)
	@echo "\npush_swap sucksesfooli created !\n"

clean :
	@$(RM) $(OBJS)
	@make clean -C $(LIB)
	rm -rf $(OBJ_DIR)
	@echo "\nall objects sucksesfooli cleaned !\n"

fclean : clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB)
	@echo "\narchives and execs sucksesfooli Fcleaned !\n"

re : fclean all

.PHONY = all clean fclean re
