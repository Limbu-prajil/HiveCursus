/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:55:07 by pdietric          #+#    #+#             */
/*   Updated: 2024/02/05 23:45:29 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STYLE_BONUS_H
# define STYLE_BONUS_H
# include "specifier_bonus.h"

int		gen_prefix(char *prefix, t_arg v, t_conv_spec *cs);
char	*add_dressed_arg(char *buf, char *prefix, char *nude, t_conv_spec *cs);

#endif
