/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:53:24 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/01 12:49:54 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//char	*ft_strdup(const char *s1);
//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>
// 
//int main(void)
//{
//    const char *s1 = "Duplicate me!";
//    char *s2 = ft_strdup(s1);
//    printf("s2 = \"%s\"\n", s2);
//    free(s2);
//}
//
char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*ptr;

	size = ft_strlen(s1) + 1;
	ptr = malloc(size);
	if (ptr != 0)
		ft_strlcpy(ptr, s1, size);
	return (ptr);
}
