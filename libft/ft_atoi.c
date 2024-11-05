#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>

int	ft_atoi(const char *s)
{
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	while ((*s == 32 || (*s >= 9 && *s <= 13)) && *s)
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + *s - '0';
		s++;
	}
	return (sign * (int)res);
}

int		main(void)
{
	char *a = "    \n\n\v\f\r\t -5432100AAAgreghrsth";
	printf("Returned integer is: %d\n",ft_atoi(a));
	printf("Returned integer is: %d\n", atoi(a));
}
