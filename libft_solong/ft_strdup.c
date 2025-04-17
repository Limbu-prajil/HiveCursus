/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:14:41 by ashobajo          #+#    #+#             */
/*   Updated: 2024/05/22 23:30:32 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*memory;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	memory = (char *) malloc (sizeof(char) * (len + 1));
	if (!memory)
		return (NULL);
	while (i < len)
	{
		memory[i] = s[i];
		i++;
	}
	memory[len] = '\0';
	return (memory);
}
