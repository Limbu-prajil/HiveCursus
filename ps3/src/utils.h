/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:25:31 by ulayus            #+#    #+#             */
/*   Updated: 2023/01/02 22:45:18 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "struct.h"

size_t	nb_values(t_list *head_a);
int		*sort_int_tab(int *tab, int len);
void	ft_listadd_front(t_list **lst, t_list *new);
void	ft_listadd_back(t_list **lst, t_list *new);
t_list	*ft_listlast(t_list *lst);
int		isempty(char *str);

#endif
