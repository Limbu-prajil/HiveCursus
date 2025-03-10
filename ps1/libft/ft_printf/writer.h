/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:14:11 by pdietric          #+#    #+#             */
/*   Updated: 2024/02/05 23:34:55 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITER_H
# define WRITER_H
# include <stdarg.h>
# include <stddef.h>
# include "specifier.h"

char	*add_str(char *buf, const char *str, t_conv_spec *cs);
char	*add_percent_literals(char *buf, t_conv_spec *cs, size_t num);
char	*add_arg(char *buf, va_list *ap, t_conv_spec *cs);

#endif
