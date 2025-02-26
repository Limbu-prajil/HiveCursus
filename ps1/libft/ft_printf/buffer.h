/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:14:11 by pdietric          #+#    #+#             */
/*   Updated: 2024/02/05 23:37:57 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H
# include "specifier.h"
# include <stddef.h>

int		print_buf(char *buf, t_conv_spec *cs);
char	*option_buffer_resize(char *buf, t_conv_spec *cs, size_t delta);

#endif
