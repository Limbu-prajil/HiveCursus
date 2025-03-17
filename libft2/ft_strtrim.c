/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:46:14 by kjullien          #+#    #+#             */
/*   Updated: 2024/11/14 22:26:20 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	ft_is_in_set(const char c, const char *set)
{
	size_t	counter;

	counter = 0;
	while (*(set + counter))
	{
		if (*(set + counter) == c)
			return (1);
		counter++;
	}
	return (0);
}

static const char	*ft_set_count(const char *s1, const char *set,
		const int start_or_end)
{
	const char	*end;

	if (start_or_end == 0)
	{
		while (*s1 && ft_is_in_set(*s1, set))
			s1++;
		return (s1);
	}
	else
	{
		end = s1 + ft_strlen(s1);
		while (end > s1 && ft_is_in_set(*(end - 1), set))
			end--;
		return (end);
	}
}

static char	*ft_handle_set_only(void)
{
	char	*r;

	r = malloc(1 * sizeof(char));
	if (!r)
		return (NULL);
	r[0] = '\0';
	return (r);
}

char				*ft_strtrim(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*p_begin;
	const char	*p_end;
	char		*r;
	size_t		counter;

	p_begin = ft_set_count(s1, set, 0);
	p_end = ft_set_count(s1, set, 1);
	if (p_begin >= p_end)
		return (ft_handle_set_only());
	r = malloc((p_end - p_begin + 1) * sizeof(char));
	if (!r)
		return (NULL);
	counter = 0;
	while ((p_begin + counter) < p_end)
	{
		r[counter] = *(p_begin + counter);
		counter++;
	}
	r[counter] = '\0';
	return (r);
}
