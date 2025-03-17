/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:03:39 by ocassany          #+#    #+#             */
/*   Updated: 2023/02/10 09:52:33 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;

	if ((!big || !little) && !len)
		return (NULL);
	len_little = ft_strlen(little);
	if (!len_little)
		return ((char *)big);
	i = 0;
	while (big[i] && i <= (len - 1))
	{
		if ((len_little + i) <= len && !ft_strncmp(&big[i], little, len_little))
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
