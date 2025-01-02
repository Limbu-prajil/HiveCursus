#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *s, ...);
int	ft_printf_char(char c);
int	ft_printf_hexlow(unsigned long num);
int	ft_printf_hexupp(unsigned long num);
int	ft_printf_nbr(int n);
int	ft_printf_string(char *s);
int	ft_printf_unbr(unsigned int nb);
int	ft_printf_pointer(void *ptr);
#endif
