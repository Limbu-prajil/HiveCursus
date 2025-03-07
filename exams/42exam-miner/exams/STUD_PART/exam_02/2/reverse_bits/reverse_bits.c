unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet);

int main(int ac, char **av)
{
    if (ac == 2)
        printf("%d", reverse_bits(av[1][0]));
    return (0);
}