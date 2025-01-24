#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

# include <stdlib.h> // NULL, malloc, free
# include <unistd.h> // read

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);

void	create_list(t_list **list, int fd);
int		found_newline(t_list *list);
void	append(t_list **list, char *buf);
t_list	*find_last_node(t_list *list);

char	*get_line(t_list *list);
int		len_to_newline(t_list *list);
void	copy_str(t_list *list, char *str);

void	polish_list(t_list **list);
t_list	*find_last_node(t_list *list);
void	dealloc(t_list **list, t_list *clean_node, char *buf);

#endif
