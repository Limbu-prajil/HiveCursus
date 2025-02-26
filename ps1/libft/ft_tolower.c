/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:33:24 by pdietric          #+#    #+#             */
/*   Updated: 2024/08/10 20:03:36 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//int	ft_tolower(int c);
//#include <ctype.h>
//#include <stdio.h>
//int	main(void)
//{
//	int c = -5000;
//	int ref = 0;
//	int my = 0;
//	while (c < 5000)
//	{
//		ref = tolower(c);
//		my = ft_tolower(c);
//		if (ref != my)
//			printf("%d:\tref=%d\tmy=%d\n", c, ref, my);
//		c++;
//	}
//	//printf(":\tref=%d\tmy=%d", isalnum(''), ft_isalnum(''));
//	//printf("%s:\tref=%d\tmy=%d", "test", isalnum("test"), ft_isalnum("test"));
//	return (0);
//}
//
int	ft_tolower(int c)
{
	if (('A' <= c) && (c <= 'Z'))
		c += 32;
	return (c);
}
