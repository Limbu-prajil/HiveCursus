#include <stdio.h>
#include <bsd/string.h>

char*	ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] == little[j] && big[i + j] != '\0' && (i + j) < len)
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
		j = 0;
	}
	return (char *)NULL;
}


int	main(void)
{
	const char *big = "crazy!";
	const char *little = "raz";
	size_t len = 6;
	
	printf("Searched string is found as: %s\n", ft_strnstr(big, little, len));
	printf("Searchd string is found as: %s\n", strnstr(big, little, len));
	
	return (0);
}
