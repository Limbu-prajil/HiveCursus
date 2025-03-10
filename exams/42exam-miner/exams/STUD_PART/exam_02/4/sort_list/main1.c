#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*sort_list(t_list *lst, int (*cmp)(int, int));

int	ascending(int a, int b)
{
	return (a <= b);
}

int	main(void)
{
	t_list *l;
	int		i;
	t_list	*t;
	t_list	*b;

	i = 10;
	l = malloc(sizeof(t_list));
	t = l;
	b = l;

	while (i)
	{
		l->data = i / 3;
		l->next = malloc(sizeof(t_list));
		l = l->next;
		--i;
	}

	l->next = NULL;

	printf("[ ");
	while (t)
	{
		printf("%d ", t->data);
		t = t->next;
	}

	printf("]\n");
	b = sort_list(b, ascending);


	printf("[ ");
	while (b)
	{
		printf("%d ", b->data);
		b = b->next;
	}
	printf("]\n");

	free(l);
	return 0;
}
