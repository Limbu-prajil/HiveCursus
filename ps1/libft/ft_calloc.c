/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:20:56 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/01 12:44:35 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void *ft_calloc(size_t count, size_t size);
//#include <stdio.h>
//#include <string.h>
//void	print_mem(void *ptr, size_t num)
//{
//	while (num-- > 0)
//	{
//		printf("%i", *((char *)ptr));
//		ptr++;
//	}
//	printf("\n");
//}
//int main(void)
//{
//	void *pref = calloc(1e15, 1);
//	void *pmy = ft_calloc(1e15, 1);
//	print_mem(pref, 6);
//	print_mem(pmy, 6);
//	return (0);
//}
//
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr != 0)
		ft_bzero(ptr, count * size);
	return (ptr);
}
