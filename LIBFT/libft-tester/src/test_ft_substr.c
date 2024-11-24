/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:37:34 by agaga             #+#    #+#             */
/*   Updated: 2024/11/03 17:22:32 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"

void test_ft_substr(char const *s, unsigned int start, size_t len, char const *expected)
{
	char *result = ft_substr(s, start, len);

	if ((result == NULL && expected == NULL) || (result != NULL && strcmp(result, expected) == 0)) 
	{
		printf("Test for: ft_substr(\"%s\", %u, %zu) == \"%s\" "GREEN" PASS\n" RESET, s, start, len, expected);
		pass_count++;
	} 
	else 
	{
		printf(RED "Test failed: ft_substr(\"%s\", %u, %zu) == \"%s\", expected \"%s\"\n" RESET, s, start, len, result ? result : "(null)", expected);
		fail_count++;
	}
	free(result);
}

int main() 
{
	test_ft_substr("Hello, World!", 7, 5, "World");
	test_ft_substr("Hello, World!", 0, 5, "Hello");
	test_ft_substr("Hello, World!", 13, 5, "");
	test_ft_substr("", 0, 5, "");
	test_ft_substr("Hello", 1, 10, "ello");
	test_ft_substr(NULL, 0, 5, NULL);
	test_ft_substr("Hello, World!", 5, 0, "");
	test_ft_substr("Hello", 0, 0, "");

	if (fail_count == 0)
		return (0);
	else
	{
		printf(RED "%d tests failed out of %d.\n" RESET, fail_count, pass_count + fail_count);
		return (1);
	}
}

