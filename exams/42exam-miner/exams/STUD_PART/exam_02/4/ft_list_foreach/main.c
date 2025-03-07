#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"
#include "ft_list_foreach.c"

void ft_putnbr(void *data)
{
	int *i;

	i = data;
	printf("%d\n", *i);
}

void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	new->data = data;
	new->next = *begin_list;
	*begin_list = new;
}



int main()
{
	t_list *list = NULL;
	int i = 9;
	int *data;
	while (i >= 0)
	{
		data = malloc(sizeof(int));
		*data = i;
		ft_list_push_front(&list, data);
		i--;
	}
	ft_list_foreach(list, &ft_putnbr);
	return (0);
}