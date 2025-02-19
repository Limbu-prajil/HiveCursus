#include "push_swap.h"
#include "ft_printf.h"

// Function to print the stack
void	print_stack(t_stack *stack, char *name)
{
	ft_printf("Stack %s: ", name);
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (!validate_args(argc, argv))
		error_exit();
	a = NULL;
	b = NULL;
	// Initialize stack a with arguments
	for (int i = 1; i < argc; i++)
		stack_add_back(&a, stack_new(ft_atoi(argv[i])));
	//print_stack(a, "a (before sorting)");
	sort_stack(&a, &b);
	//print_stack(a, "a (after sorting)");
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}