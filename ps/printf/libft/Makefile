# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrudloff <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 15:36:49 by mrudloff          #+#    #+#              #
#    Updated: 2022/12/16 19:52:47 by mrudloff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT #
NAME	= libft.a
CC		= @clang
CFLAGS	= -Wall -Wextra -Werror
RM		= @rm -f
FILE	= $(shell ls -lR src/ | grep -F .c | wc -l)
CMP		= 1
CLEAR	= @clear

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
# Libft is ready to use
RNBW	= @printf "                                                                     \r$(RED)Lib$(ORANGE)ft$(YELLOW) is$(GREEN) re$(LBLUE)ady $(INDI)to $(PURPLE)use$(RESET)\n"

# SOURCES #
SRC	= ./src/check/ft_isalnum.c\
	  ./src/check/ft_isalpha.c\
	  ./src/check/ft_isascii.c\
	  ./src/check/ft_isdigit.c\
	  ./src/check/ft_isprint.c\
	  ./src/check/ft_isspace.c\
	  ./src/list/ft_lstadd_back.c\
	  ./src/list/ft_lstadd_front.c\
	  ./src/list/ft_lstclear.c\
	  ./src/list/ft_lstdelone.c\
	  ./src/list/ft_lstiter.c\
	  ./src/list/ft_lstlast.c\
	  ./src/list/ft_lstmap.c\
	  ./src/list/ft_lstnew.c\
	  ./src/list/ft_lstsize.c\
	  ./src/memory/ft_bzero.c\
	  ./src/memory/ft_calloc.c\
	  ./src/memory/ft_memchr.c\
	  ./src/memory/ft_memcmp.c\
	  ./src/memory/ft_memcpy.c\
	  ./src/memory/ft_memmove.c\
	  ./src/memory/ft_memset.c\
	  ./src/print/ft_putchar.c\
	  ./src/print/ft_putchar_fd.c\
	  ./src/print/ft_putendl_fd.c\
	  ./src/print/ft_puthexa.c\
	  ./src/print/ft_puthexa_u.c\
	  ./src/print/ft_putnbr_base.c\
	  ./src/print/ft_putnbr_fd.c\
	  ./src/print/ft_putstr.c\
	  ./src/print/ft_putstr_fd.c\
	  ./src/print/ft_putunbr_base.c\
	  ./src/string/ft_atoi.c\
	  ./src/string/ft_atof.c\
	  ./src/string/ft_atol.c\
	  ./src/string/ft_freesplit.c\
	  ./src/string/ft_itoa.c\
	  ./src/string/ft_nbrlen_base.c\
	  ./src/string/ft_ptr_setstring.c\
	  ./src/string/ft_split.c\
	  ./src/string/ft_strcapitalize.c\
	  ./src/string/ft_strchr.c\
	  ./src/string/ft_strcmp.c\
	  ./src/string/ft_strdup.c\
	  ./src/string/ft_striteri.c\
	  ./src/string/ft_strjoin.c\
	  ./src/string/ft_strlcat.c\
	  ./src/string/ft_strlcpy.c\
	  ./src/string/ft_strlen.c\
	  ./src/string/ft_strmapi.c\
	  ./src/string/ft_strncmp.c\
	  ./src/string/ft_strnstr.c\
	  ./src/string/ft_strrchr.c\
	  ./src/string/ft_strtrim.c\
	  ./src/string/ft_substr.c\
	  ./src/string/ft_tolower.c\
	  ./src/string/ft_toupper.c\
	  ./src/string/ft_unbrlen_base.c
OBJ	= $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@printf "\r$(LBLUE)[$(RESET)$(CMP)$(LBLUE)] $(RESET)Compilation in progress... $(GREEN)$<$(BLUE) [$(RESET)$(CMP)$(BLUE)/$(RESET)$(FILE)$(BLUE)]$(RESET)                        \r"
	$(CC) $(CFLAGS) -c $< -o  $@
	@$(eval CMP=$(shell echo $$(($(CMP)+1))))

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	$(RNBW)	

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.SILENT:
	all
.PHONY: 
	all clean fclean re
