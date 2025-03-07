/*
#include <unistd.h>
int main(int ac, char **av)
{
	char asc[256] = {0};
	
	if (ac != 3)
		write(1, "check\n", 6);
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j]; j++)
		{
			if (asc[av[i][j]] == 0)
			{
				asc[av[i][j]] = 1;
				write(1, &av[i][j], 1);
			}
		}
	}
}
*/


#include <unistd.h>
int main(int ac, char **av)
{
	char asc[256] = {0};
	
	if (ac != 3)
		write(1, "check\n", 6);
	for (int i = 0; av[1][i]; i++)
	{
		for (int j = 0; av[2][j]; j++)
		{
			if ( av[1][i] == av[2][j] && asc[av[1][i]] == 0)
			{
				write(1, &av[1][i], 1);
				asc[av[1][i]] = 1;
				break;
			}
		}
		
		
	}
}

