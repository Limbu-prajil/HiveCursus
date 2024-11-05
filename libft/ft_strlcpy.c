#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>

static size_t	ft_strlength(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	x;
	
	x = ft_strlength(src);
	if (src[x] == '\0')
	{
		i = 0;
		if (size > 0)
		{
			while (src[i] != '\0' && i < (size - 1))
			{
				dest[i] = src[i];
				i++;
			}
			dest[i] = '\0';
		}
	}
	return (x);
}

int	main(void)
{
	const char *src = "asdfghjkl";
	size_t size = 5;
	char *dest = malloc(size * sizeof(char));
	if (!dest) {
		printf("Memalloc failed!");
		return (1);
	}
	
	printf("Length copy of source to destination is: %lu\n", ft_strlcpy(dest, src, size));
	printf("Length copy of source to destination is: %lu\n", strlcpy(dest, src, size));
	printf("New dest is: %s", dest);
	
	free(dest);
	return (0);
}
