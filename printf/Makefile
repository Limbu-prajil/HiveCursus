CC = cc

HDR = ft_printf.h

NAME = libftprintf.a

LIBFTNAME = libft.a

SRCS = ft_printf.c ft_printf_char.c ft_printf_string.c \
	ft_printf_nbr.c ft_printf_unbr.c ft_printf_hexlow.c \
	ft_printf_pointer.c ft_printf_hexupp.c

CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

.PHONY = all makelib clean clean re

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@ -I${HDR}

makelib:
	make -C ./libft
	mv ./libft/${LIBFTNAME} .
	mv ${LIBFTNAME} ${NAME}

$(NAME): ${OBJS} makelib
	ar -rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}
	make clean -C ./libft

fclean: clean
	rm -f ${NAME}
	make fclean -C ./libft

re: fclean all

