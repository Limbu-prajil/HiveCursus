# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulayus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 11:40:22 by ulayus            #+#    #+#              #
#    Updated: 2023/01/06 17:29:17 by ulayus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

SRC = src/parsing.c src/main.c src/check_format.c src/check_list.c\
	  src/instructions_1.c src/instructions_2.c src/low_sort.c src/normalize.c\
	  src/algo.c src/algo_utils.c src/lst_utils.c src/utils.c\

SRC_B = bonus/check_format_bonus.c bonus/check_list_bonus.c\
	  bonus/instructions_1_bonus.c bonus/instructions_2_bonus.c\
	  bonus/lst_utils_bonus.c bonus/utils_bonus.c bonus/parsing_bonus.c\
	  bonus/normalize_bonus.c bonus/instructions_parser_bonus.c\
	  bonus/checker_bonus.c\

CC = cc

CFLAGS = -g -Wall -Wextra -Werror
LIBS = -Llibft -lft -Llibft/printf -lftprintf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

all: ${NAME}

${NAME}: ${OBJ}
	@make -C ./libft
	@printf '\x1b[38;2;50;205;50mLibft compiled 🤓\n\x1b[0m'
	$(CC) ${OBJ} -o ${NAME} $(LIBS)
	@printf '\x1b[38;2;50;205;50mPush Swap compiled 🤓\n\x1b[0m'

clean:
	@rm -f $(OBJ)
	@printf '\e[5m❌ \e[0m\x1b[38;2;255;140;0mObjects removed\x1b[0m\e[5m ❌\n\e[0m'

fclean: clean
	@rm -f ${NAME}
	@make -C ./libft fclean
	@make -C ./libft/printf fclean
	@printf '\e[5m🚨 \e[0m\x1b[38;2;200;0;20mBinary removed\x1b[0m\e[5m 🚨\n\e[0m'

re: fclean all

bonus: ${BONUS}

${BONUS}: ${OBJ_B}
	@make -C ./libft > /dev/null
	@printf '\x1b[38;2;50;205;50mLibft compiled 🤓\n\x1b[0m'
	$(CC) ${OBJ_B} -o ${BONUS} $(LIBS)
	@printf '\x1b[38;2;50;205;50mChecker compiled 🤓\n\x1b[0m'

clean_b:
	@rm -f $(OBJ_B)
	@printf '\e[5m❌ \e[0m\x1b[38;2;255;140;0mBonus objects removed\x1b[0m\e[5m ❌\n\e[0m'

fclean_b: clean_b
	@rm -f ${BONUS}
	@printf '\e[5m🚨 \e[0m\x1b[38;2;200;0;20mBonus binary removed\x1b[0m\e[5m 🚨\n\e[0m'

re_b: fclean_b bonus

.PHONY: all clean fclean re bonus clean_b fclean_b re_b
