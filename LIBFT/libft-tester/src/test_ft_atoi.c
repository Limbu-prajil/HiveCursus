/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:19:22 by agaga             #+#    #+#             */
/*   Updated: 2024/11/07 15:52:21 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../util/tester.h"

void	test_ft_atoi(char *str)
{
	int result = ft_atoi(str); 
	int expected = atoi(str);

	if (result == expected)
	{
		printf(BOLD"Test for "YELLOW "%s \n" RESET, str);
		printf( CYAN "Expected %d, "BLUE "we got %d "GREEN" PASS\n" RESET, expected, result);
		//printf("\n");
		pass_count++;
	}
	else 
	{
		printf("Test for %s" RED " FAIL\n" RESET, str);
		printf("Expected %d, but we got %d\n", expected, result);
		printf("\n");
		fail_count++;
	}
}

int main(void)
{

	test_ft_atoi("   --+-+-123456789");
	test_ft_atoi("42");
	test_ft_atoi("   -42");
	test_ft_atoi("   +42");
	test_ft_atoi("   0042");
	test_ft_atoi("   -0042");
	test_ft_atoi("   +0042");
	test_ft_atoi("0");
	test_ft_atoi("-0");
	test_ft_atoi("+0");
	test_ft_atoi("2147483647"); // INT_MAX
	test_ft_atoi("-2147483648"); // INT_MIN
	test_ft_atoi("   2147483647");
	test_ft_atoi("   -2147483648");
	test_ft_atoi("   +2147483647");
	test_ft_atoi("   -+2147483648");
	test_ft_atoi("   --2147483648");

	if (fail_count == 0)
		return (0);
	else
	{
		printf(RED "%d tests failed out of %d" RESET, fail_count, pass_count + fail_count);
		return (1);
	}

}
