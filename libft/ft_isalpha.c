#include "libft.h"

int	ft_isalpha(int c)
{
	if (((char)c >= 'A' && (char)c <= 'Z')
		|| ((char)c >= 'a' && (char)c <= 'z'))
		return (1);
	else
		return (0);
}
