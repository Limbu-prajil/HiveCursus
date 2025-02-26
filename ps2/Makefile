# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocassany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 09:40:41 by ocassany          #+#    #+#              #
#    Updated: 2023/08/13 17:50:31 by ocassany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = src/main.c \
	src/check_args.c \
	src/error_msg.c \
	src/initialization.c \
	src/ft_printf.c \
	src/operations1.c \
	src/operations2.c \
	src/operations3.c \
	src/operations4.c \
	src/sort.c \
	src/sort2.c \
	src/find_limits.c \
	src/find_depth.c \
	src/best.c \
	src/calcs.c \
	src/execs.c \
	src/free_stack.c

OBJS = $(SRCS:.c=.o)

CC = gcc

LIB = inc/libft/

CFLAGS = -g -Wall -Wextra -Werror -I$(LIB)

RM = rm -rf

$(NAME) : $(OBJS) $(LIB)libft.a
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIB) -lft -o $(NAME) -lreadline
	@echo "\npush_swap successfully created !\n"

$(LIB)libft.a:
	@make -C $(LIB)

all : $(NAME)

clean :
	@$(RM) $(OBJS)
	@make clean -C $(LIB)

fclean : clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB)

re : fclean all
