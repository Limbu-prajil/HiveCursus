/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:49:42 by pdietric          #+#    #+#             */
/*   Updated: 2024/08/09 17:37:59 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "style_bonus.h"
#include "buffer_bonus.h"
#include "../libft.h"

//decide based on type and flags hash, plus, and space
//returns nullptr upon error
//the following is also ensured by function interpret_specifier() in
//specifier_bonus.c: overriddance of flag space by plus for signed conversion
//is ensured via order of if-else-statements 
//only non-zero hex values get decorated with 0x or 0X
int	gen_prefix(char *ary, t_arg v, t_conv_spec *cs)
{
	int	i;

	i = 0;
	if (ft_strchr("di", cs->type) && (v.i < 0))
		ary[0] = '-';
	else if (ft_strchr("di", cs->type) && (cs->plus))
		ary[i++] = '+';
	else if (ft_strchr("di", cs->type) && (cs->space))
		ary[i++] = ' ';
	if ((cs->type == 'p' && v.p >= 0) \
	|| (ft_strchr("xX", cs->type) && v.u > 0 && cs->hash))
		ft_strlcat(ary + i, "0x", 3);
	i = -1;
	while (cs->type == 'X' && ary[++i] != '\0')
		ary[i] = ft_toupper(ary[i]);
	return (ft_strlen(ary));
}

static void	set_width_precision(t_conv_spec *cs)
{
	if (cs->p > -1 && ft_strchr("pdiuxX", cs->type) \
	&& (unsigned long)cs->p > cs->len_nude)
		cs->num_zero = cs->p - cs->len_nude;
	if (cs->zero && ft_strchr("pdiuxX", cs->type) \
	&& cs->w > cs->num_zero + cs->len_nude + cs->len_prfx)
		cs->num_zero = cs->w - cs->len_prfx - cs->num_zero - cs->len_nude;
	else if (!cs->zero && ft_strchr("cspdiuxX%", cs->type) \
	&& cs->w > cs->len_nude + cs->num_zero + cs->len_prfx)
		cs->num_spc = cs->w - cs->len_prfx - cs->len_nude - cs->num_zero;
}

char	*add_dressed_arg(char *buf, char *prefix, char *nude, t_conv_spec *cs)
{
	size_t	count;

	set_width_precision(cs);
	count = cs->num_spc + cs->len_prfx + cs->num_zero + cs->len_nude;
	buf = option_buffer_resize(buf, cs, count);
	if (!buf)
		return (0);
	if (!cs->minus)
		ft_memset(buf + cs->len_str, ' ', cs->num_spc);
	cs->len_str += cs->num_spc * (!cs->minus);
	ft_memcpy(buf + cs->len_str, prefix, cs->len_prfx);
	cs->len_str += cs->len_prfx;
	ft_memset(buf + cs->len_str, '0', cs->num_zero);
	cs->len_str += cs->num_zero;
	ft_memcpy(buf + cs->len_str, nude, cs->len_nude);
	cs->len_str += cs->len_nude;
	if (cs->minus)
		ft_memset(buf + cs->len_str, ' ', cs->num_spc);
	cs->len_str += cs->num_spc * (cs->minus);
	return (buf);
}
