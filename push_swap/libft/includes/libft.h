/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:28:27 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/17 17:28:51 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
    int             value;
    struct s_stack  *next;
} t_stack;

size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putendl_fd(char *s, int fd);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void    ft_lstadd_back(t_stack **lst, t_stack *new_node);
void    ft_lstadd_front(t_stack **lst, t_stack *new_node);
void    ft_lstclear(t_stack **lst, int (del)(int));
void    ft_lstdelone(t_stack *lst, int (del)(int));
void    ft_lstiter(t_stack *lst, void (*f)(int));
t_stack  *ft_lstlast(t_stack *lst);
t_stack	*ft_lstmap(t_stack *lst, int (f)(int), int (del)(int));
t_stack  *ft_lstnew(int value);
int     ft_lstsize(t_stack *lst);
char		*ft_strrchr(const char *s, int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char *s);
char		**ft_split_del(char const *s, char c);
char		*ft_itoa(int n);
long    ft_atol(const char *str);
int			ft_atoi(const char *c);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isprint(int c);
int			ft_isascii(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
