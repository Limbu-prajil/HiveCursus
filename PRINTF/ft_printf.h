/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:51:46 by lalves-d          #+#    #+#             */
/*   Updated: 2024/10/24 12:51:49 by lalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *s, ...);
int	ft_printf_char(char c);
int	ft_printf_hexlow(unsigned int num);
int	ft_printf_hexupp(unsigned int num);
int	ft_printf_nbr(int n);
int	ft_printf_string(char *s);
int	ft_printf_unbr(unsigned int nb);
int	ft_printf_pointer(void *ptr);
#endif
