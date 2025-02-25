NAME = libftprintf.a

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = libft
LIBFTNAME = libft.a

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)/$(INC_DIR)

all: $(NAME)

makelib:
	make -C ./$(LIBFT_DIR)
	mv ./$(LIBFT_DIR)/${LIBFTNAME} .
	mv ${LIBFTNAME} ${NAME}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) makelib
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re makelib
