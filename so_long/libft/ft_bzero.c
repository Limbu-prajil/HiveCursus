#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	char	*str_ptr;

	str_ptr = (char *) str;
	while (len--)
		*str_ptr++ = 0;
}
