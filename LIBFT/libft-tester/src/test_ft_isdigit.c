/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:07:51 by agaga             #+#    #+#             */
/*   Updated: 2024/11/01 16:23:44 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"

void test_ft_isdigit(char c, int expected)
{
	int result = ft_isdigit(c);
	if ((result > 0 && expected == 1) || (result == 0 && expected == 0))
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
	test_ft_isdigit('A', 0);
	test_ft_isdigit('z', 0);
	test_ft_isdigit('0', 1);
	test_ft_isdigit('!', 0);
	test_ft_isdigit('4', 1);
	test_ft_isdigit('i', 0);
	test_ft_isdigit('9', 1);
	test_ft_isdigit('4', 1);

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
