# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 09:55:15 by plimbu            #+#    #+#              #
#    Updated: 2024/11/18 09:55:29 by plimbu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_strlen.c ft_putstr_fd.c ft_putchar_fd.c ft_putnbr_fd.c \
	ft_putendl_fd.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c \
	ft_isascii.c ft_toupper.c ft_tolower.c ft_memset.c ft_bzero.c \
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c \
	ft_strdup.c ft_calloc.c ft_memcpy.c ft_memmove.c ft_memcmp.c \
	ft_memchr.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_strnstr.c ft_striteri.c
NAME = libft.a
OBJ = ${SRC:.c=.o}
CC = cc
RM = rm -f
AR = ar -rcs
CFLAGS = -Wall -Wextra -Werror
HDR = libft.h

.PHONY: all clean fclean re

all: ${NAME}

$(NAME): ${OBJ}
	${AR} ${NAME} ${OBJ}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@ -I${HDR}

clean:
	${RM} ${OBJ}

fclean:	clean
	${RM} ${NAME}

re: fclean all
