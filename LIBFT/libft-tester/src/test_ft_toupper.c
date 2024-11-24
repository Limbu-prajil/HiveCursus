/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:25:21 by agaga             #+#    #+#             */
/*   Updated: 2024/11/01 17:06:13 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"

void test_ft_toupper(char c, char expected)
{
	char result = ft_toupper(c);
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
	test_ft_toupper('p', toupper('p'));
	test_ft_toupper('e', toupper('e'));
	test_ft_toupper('k', toupper('k'));
	test_ft_toupper('r', toupper('r'));
	test_ft_toupper('l', toupper('l'));
	test_ft_toupper('e', toupper('e'));


	test_ft_toupper('E', toupper('E'));
	test_ft_toupper('A', toupper('A'));
	test_ft_toupper('Z', toupper('Z'));

	test_ft_toupper('1', toupper('1'));
	test_ft_toupper('!', toupper('!'));
	test_ft_toupper(' ', toupper(' '));

	if (fail_count == 0)
		return (0);

	else
	{
		printf(RED "%d tests failed out of %d.\n" RESET, fail_count, pass_count + fail_count);
		return (1);
	}
}
