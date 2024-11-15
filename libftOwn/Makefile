CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_toupper.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_strlcpy.c \
	ft_tolower.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c

OBJS = ${SRCS:.c=.o}

NAME = libft.a

HDR = libft.h

LIBC = ar rcs

RM = rm -f

.PHONY: all clean fclean re

${OBJS}: ${SRCS}
	${CC} ${FLAGS} -c $< -o $@ -I ${HDR}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
