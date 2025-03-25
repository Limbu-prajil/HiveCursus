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

NAME = libft.a

SRCS = ft_atoi.c \
	ft_atol.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split_del.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_printf.c \
	get_next_line.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_lstadd_back.c \
	ft_lstlast.c \

OBJS = $(SRCS:.c=.o) 

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f
	
$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)
	echo "Libft sucksesfooli created!"

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean 
	$(RM) $(NAME)

re: all clean fclean
