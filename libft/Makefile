NAME = libft.a

SRCS = ft_atoi.c ft_strlen.c ft_putstr_fd.c ft_putchar_fd.c ft_putnbr_fd.c \
	ft_putendl_fd.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c \
	ft_isascii.c ft_toupper.c ft_tolower.c ft_memset.c ft_bzero.c \
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c \
	ft_strdup.c ft_calloc.c ft_memcpy.c ft_memmove.c ft_memcmp.c \
	ft_memchr.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_strnstr.c ft_striteri.c

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \

OBJS = ${SRCS:%.c=%.o}
OBJSBNS = ${BONUS:%.c=%.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
RESET = \033[0m

all:	${NAME}
		@echo "$(RED)---Done archiving I & II parts!---$(RESET)"

$(NAME): ${OBJS}
		@ar rcs ${NAME} ${OBJS}

%.o:%.c libft.h
		@echo "Compiling$(GREEN)" $< "$(RESET)"
		@${CC} ${CFLAGS} -c $< -o $@

bonus:	${OBJS} ${OBJSBNS}
		@ar rcs ${NAME} ${OBJS} ${OBJSBNS}
		@echo "$(RED)---Done archiving I & II & Bonus!---$(RESET)"

so:
		@${CC} -nostartfiles -fPIC ${CFLAGS} ${SRCS} ${BONUS}
		@${CC} -nostartfiles -shared -o libft.so ${OBJS} ${OBJSBNS}

clean:
		@${RM} ${OBJS} ${OBJSBNS}
		@echo "$(YELLOW)---Objects cleaned!---$(RESET)"

fclean:	clean
		@${RM} ${NAME}
		@echo "$(RED)----Full cleaned!---$(RESET)"

re: fclean all bonus
