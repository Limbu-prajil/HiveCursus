/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:14:44 by ocassany          #+#    #+#             */
/*   Updated: 2023/02/15 15:26:52 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	res;

	if (!nmemb || !size)
		return (malloc(0));
	res = size * nmemb;
	if (res / size != nmemb)
		return (0);
	tab = (void *)malloc(res);
	if (!tab)
		return (0);
	ft_bzero(tab, res);
	return (tab);
}
