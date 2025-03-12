#include "../../inc/push_swap.h"

void	free_stack(t_list *stack)
{
	t_list	*tmp;
	t_list	*head;

	if (!stack)
		return ;
	head = stack;
	while (stack->next != head)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	free(stack);
}
