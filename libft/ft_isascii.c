#include "libft.h"

int	ft_isascii(int c)
{
	if ((char)c >= '\0' && (char)c <= 'DEL')
	{
		return (1);
	}
	else
		return (0);
}
