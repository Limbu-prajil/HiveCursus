/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:06:40 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/30 11:06:47 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int	ft_printf(const char *s, ...);
int	ft_printf_char(char c);
int	ft_printf_hexlow(unsigned long num);
int	ft_printf_hexupp(unsigned long num);
int	ft_printf_nbr(int n);
int	ft_printf_string(char *s);
int	ft_printf_unbr(unsigned int nb);
int	ft_printf_pointer(void *ptr);

#endif
