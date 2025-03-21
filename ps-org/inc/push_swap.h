#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void	error_msg(char **arr, t_list *stack);
void	free_stack(t_list *stack);
void	free_array(char **array);

void	start_init(int argc, char **argv, t_data *stacks);
void	str_init(char **argv, t_data *stacks);
void	multi_init(int argc, char **argv, t_data *stacks);
int		not_digits(char **str);
int		duplicates(t_data *stacks);
int		not_sorted(t_list *stack);

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

int		ft_printf(const char *str, ...);
int		find_min(t_list *stack);
int		find_max(t_list *stack);

void	turk_sort(t_data *stacks);
void	sort_until_three(t_data *stacks);
void	sort_three(t_data *stacks);
void	sort_stack_a(t_data *stacks);
void	sort_stack_b(t_data *stacks);

void	opti_ops_to_stack_a(t_data *stacks, int depth_b, int opsnum);

int		find_depth(t_list *stack, int nbr);
int		best_depth_in_a(t_list *sta, int stbnbr);
int		best_opsnum(t_data *stacks, int best_depth_in_a, int depth_b);

void	rra_rrb_exec(t_data *stacks, int best_depth_in_a, int best_depth_in_b);
void	ra_rb_exec(t_data *stacks, int best_depth_in_a, int best_depth_in_b);
void	ra_rrb_exec(t_data *stacks, int best_depth_in_a, int best_depth_in_b);
void	rra_rb_exec(t_data *stacks, int best_depth_in_a, int best_depth_in_b);
void	best_ops_to_exec(t_data *stacks, int best_depth_in_a, int best_depth_in_b);

#endif
