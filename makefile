CC = cc

CCFLAGS = -Wall -Wextra -Werror

SOURCE = main.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_toupper.c ft_isalpha.c ft_isdigit.c ft_strlcpy.c ft_tolower.c

OBJECTS = $(SOURCE:.c=.o)
TARGET = libc
$(TARGET):$(OBJECTS)
	$(CC) $(CCFLAGS) -o $@ $^

clean:
	@rm -f $(TARGET) $(OBJECTS)
