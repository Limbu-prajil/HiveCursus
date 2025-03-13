/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <ulayus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:48:44 by ulayus            #+#    #+#             */
/*   Updated: 2023/01/02 22:49:06 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "utils.h"
# define INVALID 0
# define SORTED 1
# define NOT_NB 2
# define DOUBLE 3

t_list	*create_list(int ac, char **av);
int		ft_isnum(char *str);
int		issorted(t_list *head);
int		isdouble(t_list *head);
void	check_format(char **strs);
void	ft_exit(void *elem, int flag);

#endif
