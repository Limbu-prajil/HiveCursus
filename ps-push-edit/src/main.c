#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	stacks;

	stacks.a = NULL;
	stacks.b = NULL;
	if (argc > 1)
	{
		start_init(argc, argv + 1, &stacks);
		if (duplicates(&stacks))
			error_msg(NULL, stacks.a);
		if (not_sorted(stacks.a))
			turk_sort(&stacks);
		free_stack(stacks.a);
	}
	return (0);
}
