#include <stdio.h>
#include <limits.h>

char	*ft_itoa(int nbr);

int	main(void)
{
	int i = 0;
	int tab[5] = {INT_MIN, -42, 0, 42, INT_MAX};

	while (i < 5)
		printf("%s\n", ft_itoa(tab[i++]));

	return 0;
}