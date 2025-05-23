#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;
	size_t	result;

	if (nmemb == 0 || size == 0)
	{
		memory = malloc(0);
		return (memory);
	}
	result = nmemb * size;
	if (result / nmemb != size)
		return (NULL);
	memory = malloc(nmemb * size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, nmemb * size);
	return (memory);
}
