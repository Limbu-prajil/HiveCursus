/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 09:50:24 by ocassany          #+#    #+#             */
/*   Updated: 2023/02/16 16:30:59 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	len_s1;
	int	start_index;
	int	end_index;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	start_index = 0;
	while (s1[start_index] && ft_strchr(set, s1[start_index]))
		start_index++;
	end_index = len_s1 - 1;
	while (end_index >= start_index && ft_strchr(set, s1[end_index]))
		end_index--;
	return (ft_substr(s1, start_index, (end_index - start_index + 1)));
}
