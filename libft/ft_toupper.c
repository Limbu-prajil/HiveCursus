#include "libft.h"

int	ft_toupper(int c)
{
	if ((char)c >= 'A' && (char)c <= 'Z')
	{
		return (c);
	}
	else
	{
		c -= 32;
	}
	return (c);
}
