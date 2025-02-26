NAME = libftprintf.a

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = libft
LIBFTNAME = libft.a

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)/$(INC_DIR)

all: $(NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

makelib:
	make -C ./$(LIBFT_DIR)
	mv ./$(LIBFT_DIR)/${LIBFTNAME} .
	mv ${LIBFTNAME} ${NAME}

$(NAME): $(OBJS) makelib
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all makelib clean fclean re
