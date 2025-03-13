/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_parser_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:05:15 by ulayus            #+#    #+#             */
/*   Updated: 2023/01/06 17:23:50 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

int	instruction_select_1(t_list **head_a, t_list **head_b, char *instruction)
{
	if (!ft_strcmp(instruction, "ra\n"))
		ra(head_a);
	else if (!ft_strcmp(instruction, "rb\n"))
		rb(head_b);
	else if (!ft_strcmp(instruction, "rra\n"))
		rra(head_a);
	else if (!ft_strcmp(instruction, "rrb\n"))
		rrb(head_b);
	else if (!ft_strcmp(instruction, "pb\n"))
		pb(head_a, head_b);
	else if (!ft_strcmp(instruction, "pa\n"))
		pa(head_a, head_b);
	else
		return (0);
	return (1);
}

int	instruction_select(t_list **head_a, t_list **head_b, char *instruction)
{
	if (instruction_select_1(head_a, head_b, instruction))
		return (1);
	else if (!ft_strcmp(instruction, "sa\n"))
		sa(head_a);
	else if (!ft_strcmp(instruction, "sb\n"))
		sb(head_b);
	else if (!ft_strcmp(instruction, "rrr\n"))
	{
		rra(head_a);
		rrb(head_b);
	}
	else if (!ft_strcmp(instruction, "rr\n"))
		rr(head_a, head_b);
	else if (!ft_strcmp(instruction, "ss\n"))
		ss(head_a, head_b);
	else
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

void	apply_instructions(t_list **head_a, t_list **head_b)
{
	char	*tmp;

	tmp = get_next_line(0);
	while (tmp)
	{
		if (!instruction_select(head_a, head_b, tmp))
		{
			free_stacks(*head_a, *head_b);
			free(tmp);
			exit(0);
		}
		free(tmp);
		tmp = get_next_line(0);
	}
}
