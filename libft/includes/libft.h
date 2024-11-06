ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

int	ft_atoi(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
void	*my_memchr(const void *s, int c, size_t n);
int	my_memcmp(const void *s1, const void *s2, size_t n);
void	*my_memcpy(void *dest, const void *src, size_t n);
void	*my_memmove(void *dest, const void *src, size_t n);
void	*my_memset(void *s, int c, size_t n);
char*	ft_strchr(const char *s, int c);
char	*my_strdup(const char *s);
unsigned long	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
unsigned long	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char*	ft_strnstr(const char *big, const char *little, size_t len);
char*	ft_strrchr(const char *s, int c);
int	ft_tolower(int c);
int	ft_toupper(int c);

endif
