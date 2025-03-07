#include <stdio.h>
#include <stdlib.h>

void	sort_int_tab(int *tab, unsigned int size);

int main(int ac, char **av)
{
	if (ac <= 2)
	{
		printf("ENTER TWO OR MORE!");
		return 0;
	}
	int i = 0;
	int *tab = (int *)malloc(sizeof(int) * (ac -1));

	while (i < (ac -1))
	{
		tab[i] = atoi(av[i + 1]);
		i++;
	}

	printf("[ ");

	while (i > 0)
		printf("%d ", tab[--i]);

	printf("]\n");

	sort_int_tab(tab, (unsigned int)ac - 1);
	
	i = 0;
	printf("[ ");

	while (i < (ac - 1))
		printf("%d ", tab[i++]);

	printf("]\n");

	free(tab);
	return 0;
}