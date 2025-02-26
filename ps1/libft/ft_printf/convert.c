/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:29:55 by pdietric          #+#    #+#             */
/*   Updated: 2024/08/09 17:31:27 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include <stdint.h>
#include "../libft.h"

static unsigned int	ptr_digits(void *ptr, int base)
{
	uintptr_t		pow;
	unsigned int	digits;

	pow = base - 1;
	digits = 1;
	while ((uintptr_t)ptr > pow)
	{
		pow = (pow + 1) * base - 1;
		digits++;
	}
	return (digits);
}

static unsigned int	digits(long long val, int base)
{
	long long		pow;
	int				sgn;
	unsigned int	digits;

	pow = base - 1;
	sgn = 1;
	digits = 1;
	if (val < 0)
		sgn = -1;
	while (sgn * val > pow)
	{
		pow = (pow + 1) * base - 1;
		digits++;
	}
	return (digits);
}

//void functions get fed a pre-allocated buffer for them to fill
//should be able to convert pointer, unsigned int and int values into strings
//naming:
//d stands for destination
//l for length
//v for value
//pointer is cast to uintptr_t before converting to avoid compiler warnings
//initially, only pointers to union v were passed; I have changed it to
//pass-by-value to avoid letting this function modify v; there are a few claims
//on Youtube that, with modern compilers pass-by-value of structs and unions is
//even faster than via pointer
//null-terminating the string is done by the caller
static void	num_to_str(char *d, t_arg v, t_conv_spec *cs)
{
	int			bas;
	uintptr_t	ptr;
	size_t		l;

	bas = 10;
	if (ft_strchr("pxX", cs->type))
		bas = 16;
	if (ft_strchr("p", cs->type))
		ptr = (uintptr_t)v.p;
	l = cs->len_nude;
	while (ft_strchr("uxX", cs->type) && (l > 0))
	{
		*(d + --l) = (v.u % bas) + '0' + (v.u % bas > 9) * (-10 - '0' + 'a');
		v.u = v.u / bas;
	}
	while (ft_strchr("p", cs->type) && (l > 0))
	{
		*(d + --l) = (ptr % bas) + '0' + (ptr % bas > 9) * (-10 - '0' + 'a');
		ptr = ptr / bas;
	}
	while (ft_strchr("di", cs->type) && (l > 0))
	{
		*(d + --l) = (-2 * (v.i < 0) + 1) * (v.i % 10) + '0';
		v.i = v.i / bas;
	}
}

size_t	arglen(t_arg *val, t_conv_spec *cs)
{
	if (ft_strchr("c%", cs->type))
		return (1);
	else if (cs->type == 's')
		return (ft_strlen((char *)val->p));
	else if (ft_strchr("di", cs->type))
		return (digits(val->i, 10));
	else if (ft_strchr("u", cs->type))
		return (digits(val->u, 10));
	else if (ft_strchr("xX", cs->type))
		return (digits(val->u, 16));
	else if ((cs->type == 'p') && (val->p == 0))
		return (1);
	else if (cs->type == 'p')
		return (ptr_digits(val->p, 16));
	return (0);
}

char	*arg_to_basestr(t_arg val, t_conv_spec *cs)
{
	char	*base;
	size_t	i;

	base = ft_calloc(cs->len_nude + 1, sizeof(*base));
	if (!base)
		return (0);
	if (ft_strchr("c%", cs->type))
		ft_memcpy(base, &val.i, cs->len_nude);
	else if (ft_strchr("s", cs->type))
		ft_strlcpy(base, (char *)val.p, cs->len_nude + 1);
	else if (ft_strchr("pdiuxX", cs->type))
		num_to_str(base, val, cs);
	i = 0;
	while (cs->type == 'X' && base[i++] != '\0')
		base[i - 1] = ft_toupper(base[i - 1]);
	return (base);
}
