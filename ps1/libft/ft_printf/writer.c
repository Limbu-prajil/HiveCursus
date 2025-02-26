/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:27:20 by pdietric          #+#    #+#             */
/*   Updated: 2024/08/09 17:38:30 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writer.h"
#include <stdlib.h>
#include "buffer.h"
#include "convert.h"
#include "style.h"
#include "../libft.h"

char	*add_str(char *buf, const char *str, t_conv_spec *cs)
{
	size_t	len;

	if (!buf)
		return (0);
	len = ft_strlen(str);
	buf = option_buffer_resize(buf, cs, len);
	if (!buf)
		return (0);
	ft_memcpy(buf + cs->len_str, str, len);
	cs->len_str += len;
	return (buf);
}

char	*add_percent_literals(char *buf, t_conv_spec *cs, size_t num)
{
	if (!buf)
		return (0);
	buf = option_buffer_resize(buf, cs, num);
	if (!buf)
		return (0);
	ft_memset(buf + cs->len_str, '%', num);
	cs->len_str += num;
	return (buf);
}

static t_arg	get_argval(va_list *ap, t_conv_spec *cs)
{
	t_arg	val;

	if (ft_strchr("sp", cs->type))
		val.p = va_arg(*ap, void *);
	if (cs->type == 's' && val.p == 0)
		val.p = "(null)";
	else if (ft_strchr("cdi", cs->type))
		val.i = (long long)va_arg(*ap, int);
	else if (ft_strchr("uxX", cs->type))
		val.u = va_arg(*ap, unsigned int);
	else if (cs->type == '%')
		val.i = '%';
	cs->len_nude = arglen(&val, cs);
	return (val);
}

char	*add_arg(char *buf, va_list *ap, t_conv_spec *cs)
{
	char	*nude;
	t_arg	val;
	char	prefix[3];

	if (cs->type != -1)
	{
		if (!buf)
			return (0);
		val = get_argval(ap, cs);
		nude = arg_to_basestr(val, cs);
		if (!nude)
		{
			free(buf);
			return (0);
		}
		ft_memset(prefix, '\0', 3);
		cs->len_prfx = gen_prefix(prefix, val, cs);
		buf = add_dressed_arg(buf, prefix, nude, cs);
		free(nude);
	}
	return (buf);
}
