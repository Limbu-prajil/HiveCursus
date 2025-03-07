#include "ft_list.h"
#include <stdlib.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *head = lst;
	int temp;

	while (lst && lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			temp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = temp;
			lst = head;
		}
		else
			lst = lst->next;
	}
	// lst now points to the last node, so head which is lst should be asigned to lst
	lst = head;
	return (lst);
}