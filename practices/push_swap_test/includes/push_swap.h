/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:01:44 by plimbu            #+#    #+#             */
/*   Updated: 2025/02/24 20:01:48 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"
# include "ft_printf.h"

// operations
void	push_b(t_stack	**from, t_stack	**to);
void	push_a(t_stack	**from, t_stack	**to);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

// sorting
void	push_swap(t_stack	**a, t_stack	**b);
t_stack	*find_min(t_stack	*a);
void	move_to_top(t_stack	**a, t_stack	*min_node);

// parsing
bool	is_sorted(t_stack	*stack);
bool	not_integer(const char	*str);
bool	is_duplicate(t_stack	*stack, int value);
bool	not_within_int_range(const char	*str);
bool	not_valid_input(int ac, char	**av);

// stack_utils
t_stack	*create_stack(int ac, char	**av);
void	free_stack(t_stack	**stack);
void	free_split(char **split);
void	process_split(char **split, t_stack **a);
void	error_exit(t_stack	**a, t_stack	**b);
void	print_stack(t_stack	*stack, char	*name);

#endif
