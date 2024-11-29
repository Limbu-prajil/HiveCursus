/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:50:37 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/18 09:50:38 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	rt;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i])
	{
		rt = ft_putchar_fd(s[i], fd);
		if (rt == -1)
			return (-1);
		i++;
	}
	return (i);
}
