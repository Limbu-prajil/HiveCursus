/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:06:10 by lalves-d          #+#    #+#             */
/*   Updated: 2024/10/24 12:12:25 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%s
//Function to print a string

int	ft_printf_string(char *s)
{
	if (!s)
		return (ft_printf_string("(null)"));
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
