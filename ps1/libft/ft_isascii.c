/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:01:22 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/07 00:13:15 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//int	ft_isascii(int c);
//#include <ctype.h>
//#include <stdio.h>
//int	main(void)
//{
//	int c = -5000;
//	int ref = 0;
//	int my = 0;
//	while (c < 5000)
//	{
//		ref = isascii(c);
//		my = ft_isascii(c);
//		if (ref != my)
//			printf("%d:\tref=%d\tmy=%d\n", c, ref, my);
//		c++;
//	}
//	//printf(":\tref=%d\tmy=%d", isalnum(''), ft_isalnum(''));
//	//printf("%s:\tref=%d\tmy=%d", "test", isalnum("test"), ft_isalnum("test"));
//	return (0);
//}
//		
int	ft_isascii(int c)
{
	if (c < 0 || 127 < c)
		return (0);
	return (1);
}
