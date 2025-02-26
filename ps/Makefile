# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrudloff <mrudloff@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 15:20:15 by mrudloff          #+#    #+#              #
#    Updated: 2022/12/16 15:43:46 by mrudloff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT
NAME	= push_swap
CC		= @clang
CFLAGS	= -Wall -Werror -Wextra
RM		= @rm -f
CLEAR	= @clear
FILE	= $(shell ls -l src/ | grep -F .c | wc -l)
CMP		= 1

#FILE
SRC	= ./src/push_swap.c\
	  ./src/lst_utils.c\
	  ./src/push.c\
	  ./src/radix.c\
	  ./src/reverse.c\
	  ./src/rotate.c\
	  ./src/swap.c\
	  ./src/index.c\
	  ./src/simple_sort.c\
	  ./src/simple_sort_utils.c
OBJ	= $(SRC:.c=.o)

# LIBFT
PRINT_PATH	= ./printf --no-print-directory
PRINT_NAME	= ./printf/libftprintf.a

# COLOR #
GREEN	= \033[38;5;76m
RED		= \033[38;5;160m
YELLOW	= \033[38;5;226m
ORANGE	= \033[38;5;202m
PURPLE	= \033[38;5;213m
LBLUE	= \033[38;5;51m
BLUE	= \033[38;5;117m
INDI	= \033[38;5;99m
RESET	= \033[00m

# PRINT
RNBW	= @printf "\n$(RED)pu$(ORANGE)sh _$(YELLOW)swa$(GREEN)p i$(LBLUE)s re$(BLUE)ady $(INDI)to r$(PURPLE)un !$(RESET)  \n"

all: $(PRINT_NAME) $(NAME)

%.o: %.c
	@printf "\r$(LBLUE)[$(RESET)+$(LBLUE)] $(RESET)Compiling $(GREEN)$<$(BLUE) [$(RESET)$(CMP)$(BLUE)/$(RESET)$(FILE)$(BLUE)]$(RESET)                      \r"
	$(CC) $(CFLAGS) -c $< -o $@
	@$(eval CMP=$(shell echo $$(($(CMP)+1))))
	
$(PRINT_NAME):
	@make -C $(PRINT_PATH)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(PRINT_NAME) -o $(NAME)
	$(RNBW)

clean:
	@make clean -C $(PRINT_PATH)
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(PRINT_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: 
	all clean fclean re
