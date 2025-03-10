#include <stdio.h>
#include <string.h>
#include "ft_list.h"
#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *current = *begin_list;
    t_list *previous = NULL;
    t_list *tmp;

    while (current)
    {
        if (cmp(current->data, data_ref) == 0)  // data matches
        {
            tmp = current;
            if (previous)  // If it's not the first node
                previous->next = current->next;
            //else  // If it's the first node
            //    *begin_list = current->next;

            current = current->next;  // Move to the next node after the current one is removed
            free(tmp);  // Free the node
        }
        else
        {
            previous = current;  // Move previous pointer forward
            current = current->next;  // Move to the next node
        }
    }
}



void	print_list(t_list **begin_list)
{
	t_list *cur = *begin_list;
	while (cur != 0)
	{
		printf("%s\n", (char *)cur->data);
		cur = cur->next;
	}
}

int		main(void)
{
	char straa[] = "String aa";
	t_list *aa = malloc(sizeof(t_list));
	aa->next = 0;
	aa->data = straa;

	char strbb[] = "String bb";
	t_list *bb = malloc(sizeof(t_list));
	bb->next = 0;
	bb->data = strbb;

	char strcc[] = "String cc";
	t_list *cc = malloc(sizeof(t_list));
	cc->next = 0;
	cc->data = strcc;

	char strdd[] = "String dd";
	t_list *dd = malloc(sizeof(t_list));
	dd->next = 0;
	dd->data = strdd;

	aa->next = bb;
	bb->next = cc;
	cc->next = dd;

	t_list **begin_list = &aa;

	print_list(begin_list);
	printf("----------\n");
	ft_list_remove_if(begin_list, strcc, strcmp);
	print_list(begin_list);
}
