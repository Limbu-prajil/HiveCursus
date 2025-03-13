/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:18:00 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/17 16:43:22 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "struct.h"
# include "utils.h"
# include "instructions.h"
# define NOT_FOUND 0
# define TOP 1
# define BOT 2

void	push_sorted_packs(t_list **head_a, t_list **head_b);
void	send_split(int *count, t_mark *mark, t_list **head_a, t_list **head_b);
int		check_pos(t_list **head, int index);
void	push_top(int *count, t_mark *marks, t_list **head_a, t_list **head_b);
void	push_bot(int *count, t_mark *marks, t_list **head_a, t_list **head_b);

#endif
