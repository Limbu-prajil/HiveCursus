/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:15:39 by agaga             #+#    #+#             */
/*   Updated: 2024/11/01 17:12:32 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"

void test_ft_tolower(char c)
{
	char	result;
	char	expected;

	result = ft_tolower(c);
	expected = tolower(c);
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
	test_ft_tolower('A');
	test_ft_tolower('z');
	test_ft_tolower('P');
	test_ft_tolower('C');
	test_ft_tolower('c');
	test_ft_tolower('i');
	test_ft_tolower('P');
	test_ft_tolower('Q');
	test_ft_tolower('1');
	test_ft_tolower('p');
	test_ft_tolower('@');
	test_ft_tolower('t');
	test_ft_tolower('Z');

	if (fail_count == 0)
		return (0);
	else
	{
		printf(RED "%d tests failed out of %d\n" RESET, fail_count, pass_count + fail_count);
		return (1);
	}
}
