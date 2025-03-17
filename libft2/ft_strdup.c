/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:28:52 by kjullien          #+#    #+#             */
/*   Updated: 2024/11/14 22:26:49 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s);

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	s_size;

	s_size = ft_strlen(s);
	result = malloc((s_size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_memcpy(result, s, s_size + 1);
	return (result);
}
