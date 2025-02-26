/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:43:33 by pdietric          #+#    #+#             */
/*   Updated: 2024/02/07 19:30:19 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIER_H
# define SPECIFIER_H
# include <stddef.h>

typedef struct s_conv_spec
{
	size_t		pos_split;
	size_t		num_literals;
	size_t		len_str;
	size_t		sz;
	char		spec;
	char		type;
	size_t		len_prfx;
	size_t		len_nude;
}	t_conv_spec;
typedef union u_arg
{
	long long		i;
	void			*p;
	unsigned int	u;
}	t_arg;
t_conv_spec	init_conv_spec(size_t len, size_t sz);
void		parse_percent(const char *format, char *split, t_conv_spec *cs);
void		parse_specifier(const char *format, t_conv_spec *cs);

#endif
