#include <stdio.h>
#include <bsd/string.h>

unsigned long	ft_strlen(const char *str)
{
	unsigned long	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned long	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	dlen;
	unsigned long	slen;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	dlen = j;
	slen = ft_strlen(src);
	if (size == 0 || size <= dlen)
		return (slen + size);
	while (src[i] != '\0' && i < size - dlen - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dlen + slen);
}

int	main(void)
{
	char dest[20] = "Source";
	char dst[20] = "Source";
	const char *src = "Source";
	size_t size= 15;
	
	printf("Return value is :%lu\n", ft_strlcat(dest, src, size));
	printf("Return value is :%lu\n", strlcat(dst, src, size));
	printf("New dest is :%s", dest);
	
	return (0);
}
