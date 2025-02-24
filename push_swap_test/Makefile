NAME = push_swap

SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = libft
PRINTF_DIR = printf

SRCS = $(SRC_DIR)/main.c \
	$(SRC_DIR)/stack_utils.c \
	$(SRC_DIR)/parsing.c \
	$(SRC_DIR)/sorting/push_swap.c \
	$(SRC_DIR)/operations/push.c \

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)/$(INC_DIR) -I$(PRINTF_DIR)/$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
