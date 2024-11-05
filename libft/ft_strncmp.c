#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n)
		return *s1 - *s2;
	else
		return (0);
}

int	main(void)
{
	const char *s1 = "prajil";
	const char *s2 = "praJil";
	size_t n = 6;
	
	printf("Diff is: %d\n", ft_strncmp(s1, s2, n));
	printf("Diff is: %d\n", strncmp(s1, s2, n));
	
	return (0);
}
