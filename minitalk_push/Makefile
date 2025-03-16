NAME := minitalk
FLAGS := -Wall -Wextra -Werror

LIBFT_NAME := libft/libft.a
LIBFT_SOURCES := $(wildcard libft/*.c)
LIBFT_OBJECTS := $(LIBFT_SOURCES:.c=.o)

all: server client

$(NAME): all

$(LIBFT_NAME): $(LIBFT_OBJECTS)
	ar -rcs $@ $^

libft/%.o: libft/%.c libft/libft.h
	cc $(FLAGS) -c $< -o $@

server: server.o $(LIBFT_NAME)
	cc $(FLAGS) $^ -o $@

server.o: server.c minitalk.h
	cc $(FLAGS) -c $< -o $@

client: client.o $(LIBFT_NAME)
	cc $(FLAGS) $^ -o $@

client.o: client.c minitalk.h
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f client.o server.o $(LIBFT_OBJECTS)

fclean: clean
	rm -f client server $(LIBFT_NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
