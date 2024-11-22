
CC = cc

NAME = libftprintf.a

LIBFTNAME = libft.a

MY_SOURCES = ft_printf.c ft_printf_char.c ft_printf_string.c \
ft_printf_nbr.c ft_printf_unbr.c ft_printf_hexlow.c \
ft_printf_pointer.c ft_printf_hexupp.c

CFLAGS = -Wall -Wextra -Werror

OBJ = $(MY_SOURCES:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

makelib:
	make -C ./libft
	@mv ./libft/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): $(OBJ) makelib
	ar -rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	cd ./libft && make clean

fclean: clean
	@rm -f $(NAME)
	cd ./libft && make fclean

re: fclean all
