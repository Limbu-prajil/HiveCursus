#include <stdio.h>
#include <string.h>

char*	ft_strrchr(const char *s, int c)
{
	char *last = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (last);
}


int	main(void)
{
	const char *s = "Prajil Limbu";
	char c = 'i';
	char* last_occur = ft_strrchr(s, c);
	
	printf("Last occurance of the char is: %s\n", last_occur);
	printf("Last occurance of the char is: %s\n", strrchr(s,c));
	
	return (0);
}
