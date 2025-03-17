#include "libft.h"

void	ft_lstadd_back(t_data *stacks, t_list *new)
{
	t_list	*tmp;

	if (!stacks->a)
	{
		stacks->a = new;
		return ;
	}
	tmp = ft_lstlast(stacks->a);
	tmp->next = new;
	new->prev = tmp;
	new->next = stacks->a;
	stacks->a->prev = new;
	return ;
}
