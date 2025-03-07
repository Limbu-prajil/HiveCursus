
#include <unistd.h>

char lookup[127];

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int i = 0;
		while (av[2][i])
		{
			lookup[(int)av[2][i]] = 1;
			i++;
		}
		i ^= i;
		while (av[1][i])
		{
			if (lookup[(int)av[1][i]])
				ft_putchar(av[1][i]);
			lookup[(int)av[1][i]] = 0;
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
