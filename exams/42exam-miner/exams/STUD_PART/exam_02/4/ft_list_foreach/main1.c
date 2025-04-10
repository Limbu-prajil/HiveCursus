#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"
#include "ft_list_foreach.c"

void	int_doubler(void *n)
{
	int *num = (int *)n;
 	*num = *num * 2;
}

int		main(void)
{
 	t_list *pt_a = malloc(sizeof(t_list));
 	int	n_a = 0;
 	pt_a->data = &n_a;
 	pt_a->next = 0;

 	t_list *pt_b = malloc(sizeof(t_list));
 	int	n_b = 3;
 	pt_b->data = &n_b;
 	pt_b->next = 0;

 	t_list *pt_c = malloc(sizeof(t_list));
 	int	n_c = 4;
 	pt_c->data = &n_c;
 	pt_c->next = 0;

 	pt_a->next = pt_b;
 	pt_b->next = pt_c;

 	t_list *cur = pt_a;
 	while (cur != 0)
 	{
 		printf("%d, ", *(int *)(cur->data));
 		cur = cur->next;
 	}
 	printf("\n");

 	ft_list_foreach(pt_a, int_doubler);

 	cur = pt_a;
 	while (cur != 0)
 	{
 		printf("%d, ", *(int *)(cur->data));
 		cur = cur->next;
 	}
 	printf("\n");
}