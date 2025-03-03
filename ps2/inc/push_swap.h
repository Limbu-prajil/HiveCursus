#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
# include <limits.h>

int		best_combo(t_data *stacks, int depth_a, int depth_b);
int		best_depth_b(t_list *st, int nbr);
int		best_depth_a(t_list *st, int nbr);

int		check_asciinbr(char **str);
int		check_dup(t_data *stacks);
int		check_sorted(t_list *stack);

int		ft_printf(const char *str, ...);

int		find_min(t_list *stack);
int		find_max(t_list *stack);
int		find_depth(t_list *stack, int nbr);

int		rra_rrb_calc(t_data *stacks, int depth_a, int depth_b);
int		ra_rb_calc(int depth_a, int depth_b);
int		rra_rb_calc(t_data *stacks, int depth_a, int depth_b);
int		ra_rrb_calc(t_data *stacks, int depth_a, int depth_b);

void	rra_rrb_exec(t_data *stacks, int depth_a, int depth_b);
void	ra_rb_exec(t_data *stacks, int depth_a, int depth_b);
void	rra_rb_exec(t_data *stacks, int depth_a, int depth_b);
void	ra_rrb_exec(t_data *stacks, int depth_a, int depth_b);

void	combo_exec(t_data *stacks, int depth_a, int depth_b);

void	error_msg(void);

void	sort(t_data *stacks);
void	sort_three(t_data *stacks);
void	sort_a(t_data *stacks);
void	sort_until_three(t_data *stacks);

void	sa(t_data *stacks);
void	sb(t_data *stacks);
void	ss(t_data *stacks);
void	pa(t_data *stacks);
void	pb(t_data *stacks);
void	ra(t_data *stacks);
void	rb(t_data *stacks);
void	rr(t_data *stacks);
void	rra(t_data *stacks);
void	rrb(t_data *stacks);
void	rrr(t_data *stacks);

void	initialization(int argc, char **argv, t_data *stacks);
void	free_stack(t_list *stack);
void	free_array(char **array);

#endif
