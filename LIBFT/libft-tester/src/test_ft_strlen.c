/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:46:48 by agaga             #+#    #+#             */
/*   Updated: 2024/11/01 17:56:52 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"

void	test_ft_strlen(char *str)
{
	int result; 
	int expected;

	result = ft_strlen(str);
	expected = strlen(str);
	if (result == expected)
	{
		printf("Test for '%s': '%d' = '%d' "GREEN"PASS\n" RESET, str, result, expected);
		pass_count++;
	}
	else
	{
		printf("Test for '%s': '%d' != '%d' "RED"FAIL\n" RESET, str, result, expected);
		fail_count++;
	}
}

int main(void)
{
	test_ft_strlen("Hello, World!"); // Test with a string containing special characters
	test_ft_strlen("1234567890"); // Test with a string of numbers
	test_ft_strlen("abcdefghijklmnopqrstuvwxyz"); // Test with a string of lowercase letters
	test_ft_strlen("ABCDEFGHIJKLMNOPQRSTUVWXYZ"); // Test with a string of uppercase letters
	//test_ft_strlen(" "); // Test with a single space character
	//test_ft_strlen("\n"); // Test with a newline character
	test_ft_strlen("\t"); // Test with a tab character

	if (fail_count == 0)
	{
		return (0);
	}
	else
	{
		printf(RED "%d tests failed out of %d\n" RESET, fail_count, pass_count + fail_count);
		return (1);
	}
}
