/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:11:41 by agaga             #+#    #+#             */
/*   Updated: 2024/11/01 16:32:53 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"

void test_ft_isprint(char c, int expected)
{
	int result = ft_isprint(c);
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
	// Testing printable characters
	test_ft_isprint('A', 1);
	test_ft_isprint('z', 1);
	test_ft_isprint('0', 1);
	test_ft_isprint('!', 1);
	test_ft_isprint('4', 1);
	test_ft_isprint('i', 1);
	test_ft_isprint('9', 1);
	test_ft_isprint(' ', 1);
	test_ft_isprint('~', 1);

	// Testing non-printable characters
	test_ft_isprint('\0', 0);
	test_ft_isprint('\a', 0);
	test_ft_isprint('\b', 0);
	//test_ft_isprint('\t', 0);
	//test_ft_isprint('\n', 0);
	//test_ft_isprint('\r', 0);
	//test_ft_isprint('\v', 0);
	//test_ft_isprint('\f', 0);

	if (fail_count == 0)
	{
		return (0); //SUccess
	}
	else
	{
		printf(RED "%d tests failed out of %d.\n" RESET, fail_count, pass_count + fail_count);
		return (1);
	}
}

