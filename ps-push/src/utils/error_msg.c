#include "../../inc/push_swap.h"

void	error_msg(char **arr, t_list *stack)
{
	if (arr)
		free_array(arr);
	if (stack)
		free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}
