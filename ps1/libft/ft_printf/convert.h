/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:42:20 by pdietric          #+#    #+#             */
/*   Updated: 2024/02/05 23:42:51 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H
# include "specifier.h"

size_t	arglen(t_arg *val, t_conv_spec *cs);
char	*arg_to_basestr(t_arg val, t_conv_spec *cs);

#endif
