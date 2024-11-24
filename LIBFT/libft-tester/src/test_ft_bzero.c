/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:18:56 by agaga             #+#    #+#             */
/*   Updated: 2024/11/01 15:46:26 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"

int	main(void)
{
	char	buffer[10];
	int 	i;

	i = 0;
	memset(buffer, 'A', sizeof(buffer));
	ft_bzero(buffer, 5);

	while (i < 5)
	{
		if (buffer[i] != 0)
		{
			printf(RED"Test failed: ft_bzero does not work correctly\n"RESET);
			return (1);
		}
		i++;
	}
	while (i < 10)
	{
		if (buffer[i] != 'A')
		{
			printf("Test failed: ft_bzero does not work correctly\n");
			return (1);
		}
		i++;
	}
	printf("Tests : ");
	printf(GREEN"PASS\n"RESET);
	return (0);
}
