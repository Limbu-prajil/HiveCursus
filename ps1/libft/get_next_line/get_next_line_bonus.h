/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:08:21 by pdietric          #+#    #+#             */
/*   Updated: 2024/05/01 10:28:30 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stddef.h>
# include <stdbool.h>

typedef struct s_l
{
	char	*b;
	char	*pos;
	size_t	len;
	size_t	sz;
	bool	eof;
	bool	err;
}	t_l;
char	*get_next_line(int fd);
#endif
