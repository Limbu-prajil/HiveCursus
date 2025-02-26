/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:26:50 by pdietric          #+#    #+#             */
/*   Updated: 2024/08/10 20:02:34 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//int	ft_toupper(int c);
//#include <ctype.h>
//#include <stdio.h>
//int	main(void)
//{
//	int c = -5000;
//	int ref = 0;
//	int my = 0;
//	while (c < 5000)
//	{
//		ref = toupper(c);
//		my = ft_toupper(c);
//		if (ref != my)
//			printf("%d:\tref=%d\tmy=%d\n", c, ref, my);
//		c++;
//	}
//	//printf(":\tref=%d\tmy=%d", isalnum(''), ft_isalnum(''));
//	//printf("%s:\tref=%d\tmy=%d", "test", isalnum("test"), ft_isalnum("test"));
//	return (0);
//}
//		
int	ft_toupper(int c)
{
	if (('a' <= c) && (c <= 'z'))
		c -= 32;
	return (c);
}
