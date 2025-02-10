#include "../includes/push_swap.h"
#include "../libft/libft.h"

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    if (ac < 2)
        return (0);
    if (!is_valid_input(ac, av))
        error_exit(NULL, NULL);
    a = create_stack(ac, av);
    b = NULL;
    if (!is_sorted(a))
        sort_stack(&a, &b);
    free_stack(&a);
    free_stack(&b);
    return (0);
}
