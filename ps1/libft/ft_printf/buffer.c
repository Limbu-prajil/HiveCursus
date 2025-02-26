/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:27:20 by pdietric          #+#    #+#             */
/*   Updated: 2024/08/09 12:47:06 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include <unistd.h>
#include <stdlib.h>
#include "../libft.h"

char	*option_buffer_resize(char *buf, t_conv_spec *cs, size_t delta)
{
	char	*tmp;

	if (cs->sz < cs->len_str + delta)
	{
		tmp = malloc(2 * (cs->len_str + delta) * sizeof(*tmp));
		if (tmp)
		{
			ft_memcpy(tmp, buf, cs->len_str);
			cs->sz = 2 * (cs->len_str + delta);
		}
		free(buf);
		buf = tmp;
	}
	return (buf);
}

int	print_buf(char *buf, t_conv_spec *cs)
{
	int		res;

	if (!buf)
		return (-1);
	res = write(1, buf, cs->len_str);
	free(buf);
	return (res);
}
