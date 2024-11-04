#include <stdio.h>
#include <string.h>

char*	ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)NULL);
}


int	main(void)
{
	const char *s = "Prajil Limbu";
	char c = 'm';
	char* first_occur = ft_strchr(s, c);
	
	printf("First occurance of the char is: %s\n", first_occur);
	printf("First occurance of the char is: %s\n", strchr(s,c));
	
	return (0);
}
