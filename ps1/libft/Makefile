SHELL = /bin/sh
.SUFFIXES: .c .o .a
CFLAGS = -Wall -Werror -Wextra
ARFLAGS = -rcs
NAME = libft.a
VPATH = ft_printf get_next_line

src = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
src_ftpf = ft_printf.c buffer.c convert.c specifier.c style.c writer.c
src_gnl = get_next_line.c
src_bonus = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
src_ftpf_bonus = ft_printf_bonus.c buffer_bonus.c convert_bonus.c specifier_bonus.c style_bonus.c writer_bonus.c
src_gnl_bonus = get_next_line_bonus.o

obj = $(src:.c=.o)
obj_ftpf = $(src_ftpf:.c=.o)
obj_gnl = $(src_gnl:.c=.o)
obj_bonus = $(src_bonus:.c=.o)
obj_ftpf_bonus = $(src_ftpf_bonus:.c=.o)
obj_gnl_bonus = $(src_gnl_bonus:.c=.o)

.PHONY: all clean fclean re onus

all: $(NAME)

$(obj): libft.h
$(obj_ftpf) : libft.h 
ft_printf.o buffer.o writer.o convert.o style.o specifier.o : specifier.h
writer.o style.o : style.h
convert.o writer.o : convert.h
ft_printf.o writer.o style.o buffer.o : buffer.h
ft_printf.o : ft_printf.h
ft_printf.o writer.o: writer.h
$(obj_gnl) : get_next_line.h

$(obj_bonus): libft.h
$(obj_ftpf_bonus) : libft.h 
ft_printf_bonus.o buffer_bonus.o writer_bonus.o convert_bonus.o style_bonus.o specifier_bonus.o : specifier_bonus.h
writer_bonus.o style_bonus.o : style_bonus.h
convert_bonus.o writer_bonus.o : convert_bonus.h
ft_printf_bonus.o writer_bonus.o style_bonus.o buffer_bonus.o : buffer_bonus.h
ft_printf_bonus.o : ft_printf_bonus.h
ft_printf_bonus.o writer_bonus.o: writer_bonus.h
$(obj_gnl_bonus) : get_next_line_bonus.h


$(NAME): $(obj) $(obj_ftpf) $(obj_gnl)
	ar -rcs $(NAME) $(obj) $(obj_ftpf) $(obj_gnl)

clean:
	-rm $(obj) $(obj_bonus) $(obj_ftpf) $(obj_ftpf_bonus) $(obj_gnl) $(obj_gnl_bonus)

fclean: clean
	-rm $(NAME)

re: fclean all 

bonus: $(NAME)($(obj) $(obj_bonus) $(obj_ftpf_bonus) $(obj_gnl_bonus))
