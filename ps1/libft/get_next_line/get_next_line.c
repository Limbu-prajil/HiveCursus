/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:07:59 by pdietric          #+#    #+#             */
/*   Updated: 2024/05/05 17:56:06 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include "../libft.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

static void	reset_line(t_l *line)
{
	if (line->b)
		free(line->b);
	line->b = 0;
	line->pos = 0;
	line->len = 0;
	line->sz = 0;
	line->is_error = 0;
	line->is_eof = 0;
}

static char	*option_buffer_resize(t_l *l, size_t delta)
{
	char	*tmp;

	if (l->sz < l->len + delta)
	{
		l->is_error = 1;
		tmp = malloc(2 * (l->len + delta) * sizeof(*tmp));
		if (tmp)
		{
			l->is_error = 0;
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

static char	*str_from_line(int fd, t_l *line, char	*pos_new)
{
	char	*tmp;
	size_t	len;

	len = line->len;
	if (pos_new)
		len = pos_new - line->pos + 1;
	tmp = malloc((len + 1) * sizeof(*tmp));
	if (!tmp)
	{
		line->is_error = 1;
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
	static t_l	l = {0, 0, 0, 0, 0, 0};
	char		*pos_new;			
	ssize_t		bytes_read;

	pos_new = 0;
	l.is_error += fd < 0;
	if (!l.is_error && l.pos)
		pos_new = ft_strnstr(l.pos, "\n", l.len);
	if (!l.is_error && !l.is_eof && (!l.b || !pos_new))
	{
		if (!pos_new && l.len > 0)
			ft_memmove(l.b, l.pos, l.len);
		if (!option_buffer_resize(&l, BUFFER_SIZE))
			return (get_next_line(fd));
		bytes_read = read(fd, l.b + l.len, BUFFER_SIZE);
		l.is_error = bytes_read == -1;
		l.is_eof = bytes_read < BUFFER_SIZE;
		l.len += bytes_read * !l.is_error;
		return (get_next_line(fd));
	}
	else if (!l.is_error && l.b && l.len && (l.is_eof || pos_new))
		return (str_from_line(fd, &l, pos_new));
	reset_line(&l);
	return (0);
}
