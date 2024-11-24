/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:07:20 by agaga             #+#    #+#             */
/*   Updated: 2024/11/05 19:20:42 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../util/tester.h"

void	test_ft_asascii(int c)
{
	int expected = isascii(c);
	int result = ft_isascii(c);

	if (result == expected)
	{
		printf("Test for %d : "GREEN "PASS\n" RESET, c);
		//printf(BOLD BLUE "Expected: %d got %d\n" RESET, expected, result);
		pass_count++;
	}
	else
	{
		printf("Test for %d "RED "FAIL\n" RESET, c);
		printf(RED "Expected: %d but got %d\n" RESET, expected, result);
		fail_count++;
	}
}

int	main(void)
{
	test_ft_asascii(0);    // Test for null character
	test_ft_asascii(65);   // Test for 'A'
	test_ft_asascii(97);   // Test for 'a'
	test_ft_asascii(127);  // Test for DEL character
	test_ft_asascii(128);  // Test for non-ASCII character
	test_ft_asascii(-1);   // Test for negative value
	test_ft_asascii(255);  // Test for extended ASCII character
	test_ft_asascii(32);   // Test for space character
	test_ft_asascii(48);   // Test for '0'
	test_ft_asascii(90);   // Test for 'Z'
	test_ft_asascii(122);  // Test for 'z'
	test_ft_asascii(10);   // Test for newline character

	if (fail_count == 0)
		return (0);
	else
	{
		printf(RED "%d tests failed out of %d \n." RESET, fail_count, pass_count + fail_count);
		return (1);
	}
}
