/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:23:19 by plimbu            #+#    #+#             */
/*   Updated: 2025/03/27 18:23:21 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_srv
{
	char	*buf;
	char	c;
	int		buf_size;
	int		buf_idx;
	int		bit_count;
}			t_srv;

#endif
