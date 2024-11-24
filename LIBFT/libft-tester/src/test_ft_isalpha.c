/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:52:17 by agaga             #+#    #+#             */
/*   Updated: 2024/11/05 15:22:55 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"

void test_ft_isalpha(char c, int expected)
{
	int result = ft_isalpha(c);
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
	test_ft_isalpha('A', 1); // Expected PASS
	test_ft_isalpha('z', 1); // Expected PASS
	test_ft_isalpha('0', 0); // Expected FAIL
	test_ft_isalpha('!', 0); // Expected FAIL
	test_ft_isalpha('4', 0); // Expected FAIL
	test_ft_isalpha('i', 1); // Expected PASS
	test_ft_isalpha('9', 0); // Expected FAIL
	test_ft_isalpha('4', 0); // Expected FAIL

	
	if (fail_count == 0)
	{
		return (0);
	}
	else
	{
		printf(RED "%d tests failed out of %d.\n" RESET, fail_count, pass_count + fail_count);
		return (1);
	}
}

