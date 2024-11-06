CC = cc
FLAGS = -Wall -Wextra -Werror -g
SRCS = srcs/ft_atoi.c srcs/ft_bzero.c srcs/ft_calloc.c srcs/ft_isalnum.c srcs/ft_isascii.c srcs/ft_isprint.c srcs/ft_strlen.c srcs/ft_toupper.c srcs/ft_isalpha.c srcs/ft_isdigit.c srcs/ft_strlcpy.c srcs/ft_tolower.c srcs/ft_memchr.c srcs/ft_memcmp.c srcs/ft_memcpy.c srcs/ft_memmove.c srcs/ft_memset.c srcs/ft_strchr.c srcs/ft_strdup.c srcs/ft_strlcat.c srcs/ft_strcmp.c srcs/ft_strnstr.c srcs/ft_strrchr.c
OBJS = ${SRCS:.c=.o}
INCS = includes
LIB = libft.a
LIBC = ar rc
RM = rm -f

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${LIB}: ${OBJS}
	${LIBC} $@ $<

all: ${LIB}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${LIB}

re: fclean all
