/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:49:42 by pdietric          #+#    #+#             */
/*   Updated: 2024/08/10 20:05:11 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "style.h"
#include "buffer.h"
#include "../libft.h"

int	gen_prefix(char *ary, t_arg v, t_conv_spec *cs)
{
	int	i;

	i = 0;
	if (ft_strchr("di", cs->type) && (v.i < 0))
		ary[0] = '-';
	if (cs->type == 'p' && v.p >= 0)
		ft_strlcat(ary + i, "0x", 3);
	i = -1;
	while (cs->type == 'X' && ary[++i] != '\0')
		ary[i] = ft_toupper(ary[i]);
	return (ft_strlen(ary));
}

char	*add_dressed_arg(char *buf, char *prefix, char *nude, t_conv_spec *cs)
{
	size_t	count;

	count = cs->len_prfx + cs->len_nude;
	buf = option_buffer_resize(buf, cs, count);
	if (!buf)
		return (0);
	ft_memcpy(buf + cs->len_str, prefix, cs->len_prfx);
	cs->len_str += cs->len_prfx;
	ft_memcpy(buf + cs->len_str, nude, cs->len_nude);
	cs->len_str += cs->len_nude;
	return (buf);
}
