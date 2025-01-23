NAME = push_swap

SRC_DIR = src
SRC = $(SRC_DIR)/main.c \
			$(SRC_DIR)/operations_utils.c \
      $(SRC_DIR)/stack_utils.c \
      $(SRC_DIR)/input_utils.c \
      $(SRC_DIR)/sorting/simple_case.c \
      $(SRC_DIR)/sorting/medium_case.c \
      $(SRC_DIR)/operations/swap.c \
      $(SRC_DIR)/operations/push.c \
      $(SRC_DIR)/operations/rotate.c \
      $(SRC_DIR)/operations/reverse_rotate.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(LIBFT_DIR)

all: $(NAME)

%.o: %.c
				${CC} ${CFLAGS} -c $< -o $@

$(LIBFT):
				make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft

clean:
			rm -f $(OBJ)
			make -C $(LIBFT_DIR) clean

fclean: clean
				rm -f $(NAME)
				make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
