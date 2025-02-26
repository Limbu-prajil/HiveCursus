/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 08:52:30 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/07 00:13:00 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//int	ft_isalnum(int c);
//#include <ctype.h>
//#include <stdio.h>
//int	main(void)
//{
//	int c = -5000;
//	int ref = 0;
//	int my = 0;
//	while (c < 5000)
//	{
//		ref = isalnum(c);
//		my = ft_isalnum(c);
//		if (ref != my)
//			printf("%d:\tref=%d\tmy=%d\n", c, ref, my);
//		c++;
//	}
//	//printf(":\tref=%d\tmy=%d", isalnum(''), ft_isalnum(''));
//	//printf("%s:\tref=%d\tmy=%d", "test", isalnum("test"), ft_isalnum("test"));
//	return (0);
//}
//		
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
