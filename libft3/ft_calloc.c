/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:51:38 by kjullien          #+#    #+#             */
/*   Updated: 2024/11/14 22:24:32 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

void	*ft_calloc(size_t nelem, size_t elsize);

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*result;

	if (nelem != 0 && SIZE_MAX / nelem < elsize)
		return (NULL);
	result = malloc(nelem * elsize);
	if (!result)
		return (NULL);
	ft_bzero(result, nelem * elsize);
	return (result);
}
