/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:08:47 by pdietric          #+#    #+#             */
/*   Updated: 2024/08/09 17:40:45 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"
#include <stdbool.h>
#include "../libft.h"

//in the last field of split look for both leading and trailing '%' literals
void	parse_percent(const char *format, char *split, t_conv_spec *cs)
{
	char		*pos;
	ptrdiff_t	offset;

	pos = ft_strnstr(format, split, ft_strlen(format));
	offset = pos - format;
	cs->num_literals = offset / 2;
	cs->spec = (bool)(offset % 2);
}

//in the beginning assume the format string consists of literal percents only;
//in such a case split would return a null ptr and we would not enter the while
//loop in function ft_printf()
t_conv_spec	init_conv_spec(size_t len, size_t sz)
{
	t_conv_spec	cs;

	cs.len_str = len;
	cs.sz = sz;
	cs.num_literals = 0;
	cs.spec = 0;
	cs.pos_split = 0;
	cs.type = -1;
	cs.len_nude = 0;
	cs.len_prfx = 0;
	return (cs);
}

void	parse_specifier(const char *format, t_conv_spec *cs)
{
	if (cs->spec && ft_strchr("cspdiuxX", *(format + cs->pos_split)))
		cs->type = *(format + cs->pos_split++);
	if (cs->type == '\0')
	{
		cs->type = '%';
		cs->pos_split--;
	}
}
