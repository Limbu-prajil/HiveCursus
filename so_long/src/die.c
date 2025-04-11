#include "so_long.h"

void	die(char *errmsg, int errnum)
{
	if (errmsg != 0 || errnum != 0)
		ft_putstr_fd("Error: ", 2);
	//if (errmsg != 0 && errnum != 0)
	//	ft_putstr_fd(": ", 2);
	if (errmsg != 0)
		ft_putstr_fd(errmsg, 2);
	//if (errnum != 0)
	//	ft_putstr_fd(strerror(errnum), 2);
	if (errmsg != 0 || errnum != 0)
	{
		ft_putendl_fd(".", 2);
		exit(1);
	}
	exit(0);
}
