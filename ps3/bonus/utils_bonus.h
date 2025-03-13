/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:25:31 by ulayus            #+#    #+#             */
/*   Updated: 2023/01/06 16:35:09 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include <stddef.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "struct_bonus.h"
# include "instructions_bonus.h"

char	*ft_strjoin_space(char *s1, char const *s2);
size_t	nb_values(t_list *head_a);
void	add_index(t_list **head_a);
int		*sort_int_tab(int *tab, int len);
void	ft_listadd_front(t_list **lst, t_list *new);
void	ft_listadd_back(t_list **lst, t_list *new);
t_list	*ft_listlast(t_list *lst);
int		isempty(char *str);
void	free_stacks(t_list *head_a, t_list *head_b);

#endif
