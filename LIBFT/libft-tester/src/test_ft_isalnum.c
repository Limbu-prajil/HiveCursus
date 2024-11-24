/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:51:57 by agaga             #+#    #+#             */
/*   Updated: 2024/11/01 16:59:28 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"

void test_ft_isalnum(char c, int expected)
{
	int result = ft_isalnum(c);
	if (result == expected)
	{
		printf("Test for '%c': " GREEN "PASS\n" RESET, c);
		pass_count++;
	}
	else
	{
		printf("Test for '%c': " RED "FAIL\n" RESET, c);
		fail_count++;
	}
}

int main(void) 
{
	test_ft_isalnum('A', 1);
	test_ft_isalnum('z', 1);
	test_ft_isalnum('0', 1);
	test_ft_isalnum('4', 1);
	test_ft_isalnum('i', 1);
	test_ft_isalnum('9', 1);
	test_ft_isalnum('!', 0);
	test_ft_isalnum('@', 0);
	test_ft_isalnum(' ', 0);
	test_ft_isalnum('#', 0);
	test_ft_isalnum('%', 0);

	if (fail_count == 0)
		return (0);
	else
	{
		printf(RED "%d tests failed out of %d.\n" RESET, fail_count, pass_count + fail_count);
		return (1);
	}
}
