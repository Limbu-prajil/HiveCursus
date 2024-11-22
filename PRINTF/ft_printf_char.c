/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:21:24 by lalves-d          #+#    #+#             */
/*   Updated: 2024/10/24 11:26:40 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%c
//Function to print a character

int	ft_printf_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
