/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:33:45 by agaga             #+#    #+#             */
/*   Updated: 2024/11/07 16:25:28 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"

void	test_ft_itoa(int n, char *expected)
{
	char *result = ft_itoa(n);

	if (strcmp(result, expected) == 0)
	{
		printf("Test for '%d': "GREEN "PASS\n" RESET, n);
		printf("Expected: \"%s\", got: \"%s\"\n", expected, result);
		pass_count++;
	}
	else
	{
		printf("Test for '%d': "RED "FAIL\n" RESET, n);
		printf("Expected: \"%s\", got: \"%s\"\n", expected, result);
		fail_count++;
	}
	free(result);
}

int main(void) 
{
	test_ft_itoa(-123445, "-123445");
	test_ft_itoa(12345, "12345");
	test_ft_itoa(-4978, "-4978");
	test_ft_itoa(456321, "456321");
	test_ft_itoa(0, "0");
	test_ft_itoa(-1, "-1");
	test_ft_itoa(1, "1");
	test_ft_itoa(1000000000, "1000000000");
	test_ft_itoa(-1000000000, "-1000000000");
	test_ft_itoa(2147483647, "2147483647"); // INT_MAX
	test_ft_itoa(-2147483648, "-2147483648"); // INT_MIN
	test_ft_itoa(42, "42");
	test_ft_itoa(-42, "-42");
	test_ft_itoa(987654321, "987654321");
	test_ft_itoa(-987654321, "-987654321");

	if (fail_count == 0)
		return (0);
	else
	{
		printf(RED "%d tests failed out of %d.\n" RESET, fail_count, pass_count + fail_count);
		return (1);
	}
}
