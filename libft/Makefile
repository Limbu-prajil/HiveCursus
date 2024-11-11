CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS = ./ft_atoi.c ./ft_bzero.c ./ft_calloc.c ./ft_isalnum.c ./ft_isascii.c ./ft_isprint.c ./ft_strlen.c ./ft_toupper.c ./ft_isalpha.c ./ft_isdigit.c ./ft_strlcpy.c ./ft_tolower.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c ./ft_memset.c ./ft_strchr.c ./ft_strdup.c ./ft_strlcat.c ./ft_strncmp.c ./ft_strnstr.c ./ft_strrchr.c

MAIN = ../main/ft_atoi_main.c ../main/ft_bzero_main.c ../main/ft_calloc_main.c ../main/ft_isalnum_main.c ../main/ft_isascii_main.c ../main/ft_isprint_main.c ../main/ft_strlen_main.c ../main/ft_toupper_main.c ../main/ft_isalpha_main.c ../main/ft_isdigit_main.c ../main/ft_strlcpy_main.c ../main/ft_tolower_main.c ../main/ft_memchr_main.c ../main/ft_memcmp_main.c ../main/ft_memcpy_main.c ../main/ft_memmove_main.c ../main/ft_memset_main.c ../main/ft_strchr_main.c ../main/ft_strdup_main.c ../main/ft_strlcat_main.c ../main/ft_strncmp_main.c ../main/ft_strnstr_main.c ../main/ft_strrchr_main.c

OBJS = ${SRCS:.c=.o}

OBJM = ${MAIN:.c=.o}

NAME = libft.a

TEST = test.out

HDR = libft.h

LIBC = ar rc

RM = rm -f

.c.o:
	${CC} ${FLAGS} -c $< -o $@ -I ${HDR}

${NAME}: ${OBJS}
	${LIBC} $@ $<
	
${TEST}: ${OBJM}
	${LIBC} $@ $<

all: ${NAME} ${TEST}

clean:
	${RM} ${OBJS}
	${RM} ${OBJM}

fclean: clean
	${RM} ${NAME}
	${RM} ${TEST}

re: fclean all
