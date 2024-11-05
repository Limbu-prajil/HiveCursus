#include <stdio.h>
#include <string.h>

unsigned long	ft_strlen(const char *str)
{
	unsigned long	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(void)
{
	const char *str = "Evaluation is happening!";
	printf("The length of string is: %lu\n",  ft_strlen(str));
	printf("The length of string is: %lu\n", strlen(str));
	
	return (0);
}
