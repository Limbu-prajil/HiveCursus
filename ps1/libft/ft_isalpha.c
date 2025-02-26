/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:03:58 by pdietric          #+#    #+#             */
/*   Updated: 2024/08/10 20:01:54 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <ctype.h>
int	ft_isalpha(int c);
int main(void)
{
	int c = -127;
	while(c<256)
	{
		printf("%d:\tref=%d\tmy=%d\n", c, isalpha(c), ft_isalpha(c));
		c++;
	}
	return(0);
}*/
int	ft_isalpha(int c)
{
	if ((c < 'A') || (('Z' < c) && (c < 'a')) || ('z' < c))
		return (0);
	else
		return (1);
}
