/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdietric <pdietric@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:18:55 by pdietric          #+#    #+#             */
/*   Updated: 2023/11/07 00:13:30 by pdietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <ctype.h>
int	ft_isdigit(int c);
int main(void)
{
	int c = -127;
	while(c<256)
	{
		printf("%d:\tref=%d\tmy=%d\n", c, isdigit(c), ft_isdigit(c));
		c++;
	}
	return(0);
}*/
int	ft_isdigit(int c)
{
	if ((c < '0') || ('9' < c))
		return (0);
	else
		return (1);
}
