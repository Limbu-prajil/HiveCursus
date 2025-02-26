/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:10:20 by pdietric          #+#    #+#             */
/*   Updated: 2024/08/09 23:52:07 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	h;

	n = 0;
	h = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*(needle + n) != '\0')
	{
		if (h + n >= len || *(haystack + n + h) == '\0')
			return (0);
		if (*(needle + n) == *(haystack + h + n))
			n++;
		else
		{
			h++;
			n = 0;
		}
	}
	return ((char *)haystack + h);
}
