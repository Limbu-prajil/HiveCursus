#include "libft.h"

char*	ft_strdup(const char *s)
{
	size_t len;
	char *dup;
	
	len = ft_strlen(s) + 1;
	dup = malloc(len);
	if (dup)
		ft_memcpy(dup, s, len); 
	return (dup);
}
