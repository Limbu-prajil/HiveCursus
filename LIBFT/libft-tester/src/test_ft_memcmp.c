/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:00:11 by agaga             #+#    #+#             */
/*   Updated: 2024/11/04 19:55:22 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"

void test_ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int result = ft_memcmp(s1, s2, n);
	int expected = memcmp(s1, s2, n);

	if (result == expected)
	{
		printf("Test for memcmp: "GREEN"PASS\n" RESET);
		pass_count++;
	}
	else
	{
		printf("Test for memcmp: "RED"FAIL\n" RESET);
		fail_count++;
	}
}

int main(void) {
	char str1[] = "hello, world";
	char str2[] = "hello, world";
	char str3[] = "hello, there";

	test_ft_memcmp(str1, str2, 12); // Expecting PASS
	test_ft_memcmp(str1, str3, 12); // Expecting FAIL
	test_ft_memcmp(str1, str1, 12); // Expecting PASS
	test_ft_memcmp(str1, str3, 5);  // Expecting FAIL
	test_ft_memcmp(str1, str2, 0);  // Expecting PASS

	if (fail_count == 0)
		return (0);
	else
	{
		printf(RED "%d tests failed out of %d\n" RESET, fail_count, pass_count + fail_count);
		return (1);
	}
}
