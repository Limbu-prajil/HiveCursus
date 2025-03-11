#include <stdlib.h>
# define WD_NUM 100
# define WD_LEN 100

char	**ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char **tab = (char**)malloc(sizeof(char*) * WD_NUM);

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] > 32)
		{
			k = 0;
			tab[j] = (char*)malloc(sizeof(char) * WD_LEN);
			while (str[i] > 32)
			{
				tab[j][k] = str[i];
				i++;
				k++;
			}
			tab[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}
