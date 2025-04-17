#include "so_long.h"

void	error(char *errmsg)
{
	if (errmsg != 0)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(errmsg, 2);
	}
	if (errmsg != 0)
	{
		ft_putendl_fd(".", 2);
		exit(1);
	}
	exit(0);
}
