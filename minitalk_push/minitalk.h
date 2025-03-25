#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_srv
{
	char	*buf;
	char	c;
	int		buf_size;
	int		buf_idx;
	int		bit_count;
}			t_srv;

#endif