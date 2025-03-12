#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	stacks;

	stacks.a = NULL;
	stacks.b = NULL;
	if (argc > 1)
	{
		initialization(argc, argv + 1, &stacks);
		if (check_dup(&stacks))
			error_msg(NULL, stacks.a);
		if (!check_sorted(stacks.a))
			sort(&stacks);
		free_stack(stacks.a);
	}
	return (0);
}
