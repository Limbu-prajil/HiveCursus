/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:27:52 by plimbu            #+#    #+#             */
/*   Updated: 2024/11/11 16:27:58 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (((char)c >= 'A' && (char)c <= 'Z')
		|| ((char)c >= 'a' && (char)c <= 'z'))
		return (1);
	else
		return (0);
}