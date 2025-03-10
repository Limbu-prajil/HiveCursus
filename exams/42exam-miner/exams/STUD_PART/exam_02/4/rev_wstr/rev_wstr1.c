#include <unistd.h>
#include <stdio.h>

void	rev_wstr(char *str)
{
	int i = 0;
	int j;
	int first_word = 0;

	while (str[i] != '\0')
		++i;
	--i;
	while (i > 0)
	{
		printf("i = %d\n", i);
		while (str[i] == ' ' || str[i] == '\t')
			--i;
		printf("i = %d\n", i);
		j = i;
		while (j >= 0 && str[j] != ' ' && str[j] != '\t')
			--j;
			
		printf("j = %d\n", j);
		if (first_word == 1)
			write(1, " ", 1);
		write(1, str + j + 1, i - j);
		first_word = 1;
		i = j;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);

	write(1, "\n", 1);
	return (0);
}

/*
./a.out "test this" | cat -e
this test$
i = 8$
i = 8$
j = 4$
i = 4$
i = 3$
j = -1$
*/
