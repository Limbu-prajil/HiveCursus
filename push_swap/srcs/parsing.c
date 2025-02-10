#include "../includes/push_swap.h"
#include "../libft/libft.h"

int     is_valid_input(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            if (!ft_isdigit(av[i][j]) && av[i][j] != '-')
                return (0);
            j++;
        }
        if (ft_atoi(av[i]) < INT_MIN || ft_atoi(av[i]) > INT_MAX)
            return (0);
        i++;
    }
    return (1);
}
