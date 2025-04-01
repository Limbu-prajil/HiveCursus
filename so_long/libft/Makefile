# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 17:05:59 by ashobajo          #+#    #+#              #
#    Updated: 2024/05/24 17:14:43 by ashobajo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

NAME = libft.a

SRCS = ft_isprint.c ft_isdigit.c ft_isascii.c ft_isalpha.c ft_isalnum.c ft_toupper.c ft_tolower.c ft_atoi.c ft_memcmp.c ft_strncmp.c \
       ft_itoa.c ft_strdup.c ft_split.c ft_strchr.c ft_strrchr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_substr.c ft_strnstr.c \
       ft_bzero.c ft_calloc.c ft_memset.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c \
       ft_putendl_fd.c ft_striteri.c ft_strlen.c ft_strlcat.c ft_strlcpy.c ft_strcmp.c \

OBJS = $(SRCS:.c=.o)

BSRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c ft_lstclear.c ft_lstmap.c

BOBJS = $(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(BOBJS)
	ar rcs $(NAME) $(BOBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
