/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:07:59 by pdietric          #+#    #+#             */
/*   Updated: 2024/05/01 10:27:53 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>
#include "../libft.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
#define FDMAX 256

void	reset_line(t_l *line)
{
	if (line->b)
		free(line->b);
	line->b = 0;
	line->pos = 0;
	line->len = 0;
	line->sz = 0;
	line->err = 0;
	line->eof = 0;
}

char	*option_buffer_resize(t_l *l, size_t delta)
{
	char	*tmp;

	if (l->sz < l->len + delta)
	{
		l->err = 1;
		tmp = malloc(2 * (l->len + delta) * sizeof(*tmp));
		if (tmp)
		{
			l->err = 0;
			if (l->b)
				ft_memcpy(tmp, l->b, l->len);
			l->sz = 2 * (l->len + delta);
		}
		free(l->b);
		l->b = tmp;
	}
	l->pos = l->b;
	return (l->b);
}

char	*str_from_line(int fd, t_l *line, char	*pos_new)
{
	char	*tmp;
	size_t	len;

	len = line->len;
	if (pos_new)
		len = pos_new - line->pos + 1;
	tmp = malloc((len + 1) * sizeof(*tmp));
	if (!tmp)
	{
		line->err = 1;
		return (get_next_line(fd));
	}
	*(tmp + len) = '\0';
	ft_memcpy(tmp, line->pos, len);
	if (pos_new)
	{
		line->pos = pos_new + 1;
		line->len -= len;
	}
	else
		reset_line(line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static t_l	l[FDMAX] = {{0, 0, 0, 0, 0, 0}};
	char		*pos_new;			
	ssize_t		bytes_read;

	if (!(0 <= fd && fd < FDMAX))
		return (0);
	pos_new = 0;
	if (!l[fd].err && l[fd].pos)
		pos_new = ft_strnstr(l[fd].pos, "\n", l[fd].len);
	if (!l[fd].err && !l[fd].eof && (!l[fd].b || !pos_new))
	{
		if (!pos_new && l[fd].len > 0)
			ft_memmove(l[fd].b, l[fd].pos, l[fd].len);
		if (!option_buffer_resize(&l[fd], BUFFER_SIZE))
			return (get_next_line(fd));
		bytes_read = read(fd, l[fd].b + l[fd].len, BUFFER_SIZE);
		l[fd].err = bytes_read == -1;
		l[fd].eof = bytes_read < BUFFER_SIZE;
		l[fd].len += bytes_read * !l[fd].err;
		return (get_next_line(fd));
	}
	else if (!l[fd].err && l[fd].b && l[fd].len && (l[fd].eof || pos_new))
		return (str_from_line(fd, &l[fd], pos_new));
	reset_line(&l[fd]);
	return (0);
}
