#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_lst;

	new_lst = malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst->prev = new_lst;
	new_lst->nbr = content;
	new_lst->next = new_lst;
	return (new_lst);
}
