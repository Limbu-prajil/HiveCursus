#ifndef MAIN_H
# define MAIN_H

typedef struct s_stack
{
	int	sz;
	int	top;
	int	*ary;
}		t_stack;

typedef struct s_rot
{
	int	common;
	int	count_a;
	int	count_b;
}		t_rot;
#endif
