/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:15:20 by agaga             #+#    #+#             */
/*   Updated: 2024/11/01 19:08:20 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"

void test_ft_memchr(const char *str, int c, size_t n)
{
	void *std_result = memchr(str, c, n);
	void *ft_result = ft_memchr(str, c, n);

	if (std_result == ft_result)
	{
		printf("Test for memchr(\"%s\", '%c', %zu): "GREEN"PASS\n" RESET, str, c, n);
		pass_count++;
	}
	else
	{
		printf("Test for memchr(\"%s\", '%c', %zu): "RED"FAIL\n" RESET, str, c, n);
		fail_count++;
	}
}

int main(void)
{
	test_ft_memchr("hello, world", 'w', 12);  // Found within range
	test_ft_memchr("hello, world", 'z', 12);  // Not found
	test_ft_memchr("hello, world", 'o', 5);   // Found within range, limited length
	test_ft_memchr("hello, world", '\0', 12); // Test for null character
	test_ft_memchr("hello, world", 'd', 12);  // Found at the end
	test_ft_memchr("hello, world", 'o', 0);   // Zero length (should not search)
	
	if (fail_count == 0)
		return (0);
	else
	{
		printf(RED "%d tests failed out of %d\n" RESET, fail_count, pass_count + fail_count);
		return (1);
	}
}

