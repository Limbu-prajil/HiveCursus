/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:08:32 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/30 11:08:35 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_string(char *s)
{
	if (!s)
		return (ft_printf_string("(null)"));
	if (ft_putstr_fd(s, 1) == -1)
		return (-1);
	return (ft_strlen(s));
}
