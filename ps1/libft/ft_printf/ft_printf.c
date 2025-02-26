/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:35:53 by pdietric          #+#    #+#             */
/*   Updated: 2024/08/09 17:35:48 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <stdarg.h>
#include "writer.h"
#include "buffer.h"
#include "specifier.h"
#include "../libft.h"
#define BUFFER_SIZE 0

static char	**clean(char	**p)
{
	size_t	pn;

	pn = 0;
	while (*(p + pn) != 0)
	{
		free(*(p + pn));
		pn++;
	}
	free(p);
	return (0);
}

static int	vft_printf(const char *format, va_list *args)
{
	char		**split;
	char		*buf;
	size_t		i;
	t_conv_spec	cs;

	split = ft_split(format, '%');
	if (!split)
		return (-1);
	buf = malloc(BUFFER_SIZE * sizeof(*buf));
	cs = init_conv_spec(0, BUFFER_SIZE);
	i = 0;
	while (split && buf && *(split + i) != 0)
	{
		cs = init_conv_spec(cs.len_str, cs.sz);
		parse_percent(format, *(split + i), &cs);
		buf = add_percent_literals(buf, &cs, cs.num_literals);
		parse_specifier(*(split + i), &cs);
		buf = add_arg(buf, args, &cs);
		buf = add_str(buf, *(split + i) + cs.pos_split, &cs);
		format += cs.num_literals * 2 + cs.spec + (cs.type == '%') \
				+ ft_strlen(*(split + i++));
	}
	buf = add_percent_literals(buf, &cs, ft_strlen(format) / 2);
	clean(split);
	return (print_buf(buf, &cs));
}

//split format string along %, multiple % in a row are condensed
//follow suggestion at https://stackoverflow.com/a/64035688/23266062
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = vft_printf(format, &args);
	va_end(args);
	return (res);
}
