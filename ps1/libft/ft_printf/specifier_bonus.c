/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:08:47 by pdietric          #+#    #+#             */
/*   Updated: 2024/08/09 23:47:52 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_bonus.h"
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
	cs.minus = false;
	cs.plus = false;
	cs.space = false;
	cs.hash = false;
	cs.zero = false;
	cs.w = 0;
	cs.p = -1;
	cs.len_nude = 0;
	cs.len_prfx = 0;
	cs.num_zero = 0;
	cs.num_spc = 0;
	return (cs);
}

//void	parse_specifier(const char *format, t_conv_spec *cs)
//			&& ft_strchr("-+ #0", *(format + cs->pos_split)))
//	{
//		if (*(format + cs->pos_split) == '-')
//			cs->minus = true;
//		else if (*(format + cs->pos_split) == '+')
//			cs->plus = true+;
//		else if (*(format + cs->pos_split) == ' ')
//			cs->space = true;
//		else if (*(format + cs->pos_split) == '#')
//			cs->hash = true;
//		else
//			cs->zero = true;
//		cs->pos_split++;
//	}
//	if (cs->spec)
//		cs->w = ft_atoi(format + cs->pos_split);
//	while (cs->spec && ft_isdigit(*(format + cs->pos_split)))
//		cs->pos_split++;
//	if (cs->spec && *(format + cs->pos_split) == '.')
//		cs->p = ft_atoi(format + ++cs->pos_split);
//	while (cs->spec && ft_isdigit(*(format + cs->pos_split)))
//		cs->pos_split++;
//	if (cs->spec && ft_strchr("cspdiuxX", *(format + cs->pos_split)))
//		cs->type = *(format + cs->pos_split++);
//	interpret_specifier(cs);
//}
//
/*
void	parse_specifier(const char *format, t_conv_spec *cs)
{
	while (cs->spec && *(format + cs->pos_split) != '\0' \
			&& ft_strchr("-+ #0", *(format + cs->pos_split)))
	{
		cs->minus += (*(format + cs->pos_split) == '-');
		cs->plus += (*(format + cs->pos_split) == '+');
		cs->space += (*(format + cs->pos_split) == ' ');
		cs->hash += (*(format + cs->pos_split) == '#');
		cs->zero += (*(format + cs->pos_split) == '0');
		cs->pos_split++;
	}
	if (cs->spec)
		cs->w = ft_atoi(format + cs->pos_split);
	while (cs->spec && ft_isdigit(*(format + cs->pos_split)))
		cs->pos_split++;
	if (cs->spec && *(format + cs->pos_split) == '.')
		cs->p = ft_atoi(format + ++cs->pos_split);
	while (cs->spec && ft_isdigit(*(format + cs->pos_split)))
		cs->pos_split++;
	if (cs->spec && ft_strchr("cspdiuxX", *(format + cs->pos_split)))
		cs->type = *(format + cs->pos_split++);
	interpret_specifier(cs);
}
*/
static void	consume_flags(const char *format, t_conv_spec *cs)
{
	while (cs->spec && *(format + cs->pos_split) != '\0' \
			&& ft_strchr("-+ #0", *(format + cs->pos_split)))
	{
		cs->minus += (*(format + cs->pos_split) == '-');
		cs->plus += (*(format + cs->pos_split) == '+');
		cs->space += (*(format + cs->pos_split) == ' ');
		cs->hash += (*(format + cs->pos_split) == '#');
		cs->zero += (*(format + cs->pos_split) == '0');
		cs->pos_split++;
	}
}

static void	consume_width_prec(const char *format, t_conv_spec *cs)
{
	if (cs->spec && ft_isdigit(*(format + cs->pos_split)))
		cs->w = ft_atoi(format + cs->pos_split);
	while (cs->spec && ft_isdigit(*(format + cs->pos_split)))
		cs->pos_split++;
	consume_flags(format, cs);
	if (cs->spec && *(format + cs->pos_split) == '.')
		cs->p = ft_atoi(format + ++cs->pos_split);
	while (cs->spec && ft_isdigit(*(format + cs->pos_split)))
		cs->pos_split++;
}

void	parse_specifier(const char *format, t_conv_spec *cs)
{
	while (cs->spec && !ft_strchr("cspdiuxX", *(format + cs->pos_split)) \
			&& ft_strchr("123456789+-.#0 ", *(format + cs->pos_split)))
	{
		consume_flags(format, cs);
		consume_width_prec(format, cs);
	}
	if (cs->spec && ft_strchr("cspdiuxX", *(format + cs->pos_split)))
		cs->type = *(format + cs->pos_split++);
	if (cs->minus || cs->p >= 0)
		cs->zero = false;
	if (cs->plus)
		cs->space = false;
	if (cs->type == 'p')
		cs->hash = true;
	if (!ft_strchr("pxX", cs->type))
		cs->hash = false;
	if (cs->type == '\0')
	{
		cs->type = '%';
		cs->pos_split--;
	}
}
