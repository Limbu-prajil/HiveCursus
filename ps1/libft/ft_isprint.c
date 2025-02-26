/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:17:06 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/07 00:13:45 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//int	ft_isprint(int c);
//#include <ctype.h>
//#include <stdio.h>
//int	main(void)
//{
//	int c = -5000;
//	int ref = 0;
//	int my = 0;
//	while (c < 5000)
//	{
//		ref = isprint(c);
//		my = ft_isprint(c);
//		if (ref != my)
//			printf("%d:\tref=%d\tmy=%d\n", c, ref, my);
//		c++;
//	}
//	//printf(":\tref=%d\tmy=%d", isalnum(''), ft_isalnum(''));
//	//printf("%s:\tref=%d\tmy=%d", "test", isalnum("test"), ft_isalnum("test"));
//	return (0);
//}
//		
int	ft_isprint(int c)
{
	if (c < 32 || 126 < c)
		return (0);
	return (1);
}
