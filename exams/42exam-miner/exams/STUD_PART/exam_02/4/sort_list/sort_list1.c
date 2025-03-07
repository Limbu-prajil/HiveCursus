#include "ft_list.h"
#include <stdlib.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *head = lst;
	int temp;

	while (head && head->next)
	{
		if (cmp(head->data, head->next->data) == 0)
		{
			temp = head->next->data;
			head->next->data = head->data;
			head->data = temp;
			head = lst;
		}
		else
			head = head->next;
	}
	// head points to the last node but lst still points to first node
	return (lst);
}
