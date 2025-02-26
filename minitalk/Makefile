NAME 				:= minitalk
FLAGS 				:= -Wall -Wextra -Werror

LIBFT_NAME 			:= libft/libft.a
LIBFT_SOURCES 		:= ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
	ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
	ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
	ft_lstiter_bonus.c ft_lstmap_bonus.c \
	ft_printf.c ft_printf_hexadecimal.c	ft_printf_integer.c \
	ft_printf_unsigned_integer.c get_next_line.c
LIBFT_SOURCES 		:= $(addprefix libft/,$(LIBFT_SOURCES))
LIBFT_OBJECTS 		:= $(LIBFT_SOURCES:.c=.o)


all: server client

$(NAME): all

$(LIBFT_NAME): $(LIBFT_OBJECTS)
	ar -rcs $@ $^

libft/%.o: libft/%.c libft/libft.h
	cc $(FLAGS) -c $< -o $@

server: server.o libft/libft.a
	cc $(FLAGS) $^ -o $@

server.o: server.c
	cc $(FLAGS) -c $^ -o $@

client: client.o libft/libft.a
	cc $(FLAGS) $^ -o $@

client.o: client.c
	cc $(FLAGS) -c $^ -o $@

clean:
	rm -rf client.o server.o $(LIBFT_OBJECTS)

fclean: clean
	rm -rf client server $(LIBFT_NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re

