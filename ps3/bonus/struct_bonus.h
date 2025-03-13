/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <ulayus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:22:49 by ulayus            #+#    #+#             */
/*   Updated: 2023/01/06 16:34:48 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

typedef struct s_list
{
	int				nb;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_mark
{
	int	len;
	int	len_packs;
	int	low;
	int	high;
}		t_mark;

#endif
