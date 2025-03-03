#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

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

void	do_push(t_stack *src, t_stack *dst, t_rot act, char dst_stk);
int	*init_stack(t_stack *stack, char **strary, int fillmode);
void	do_sort3(t_stack *stk);
int	get_index_dest(t_stack stk, int nb, char dest);
int	get_index_min(t_stack stk);
int	push(t_stack *dest, t_stack *src);
void	rerot(t_stack *stk);
void	rot(t_stack *stk);
void	sort(t_stack *a, t_stack *b);
void	swap(t_stack *stk);
t_rot	whatif_push_ab(int idxa, t_stack a, t_stack b, char dest);
int	check_bonus(t_stack *a, t_stack *b);

#endif
