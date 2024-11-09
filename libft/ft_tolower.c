#include "libft.h"

int	ft_tolower(int c)
{
	if ((char)c >= 'a' && (char)c <= 'z')
	{
		return (c);
	}
	else
	{
		c += 32;
	}
	return (c);
}
