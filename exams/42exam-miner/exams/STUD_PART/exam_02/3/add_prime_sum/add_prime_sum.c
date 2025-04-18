#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putposnbr(int n)
{
	if (n > 9)
		ft_putposnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int		ft_atoi_nc(char *s)
{
	int	r = 0;
	while (*s >= '0' && *s <= '9')
		r = r * 10 + *s++ - '0';
	return (r);
}

int is_prime(int n)
{
	int i = 2;
	while (i < n)
		if (!(n % i++))
			return (0);
	return (1);
}

void	add_prime_sum(int n)
{
	int	i;
	int	prime_sum = 0;
	if (n == 1)
		prime_sum = 1;
	i = 1;
	while (++i <= n)
		if (is_prime(i))
			prime_sum += i;
	ft_putposnbr(prime_sum);
}

int		main(int ac, char **av)
{
	if (ac == 2 && ft_atoi_nc(av[1]) > 0)
		add_prime_sum(ft_atoi_nc(av[1]));
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (1);
}
