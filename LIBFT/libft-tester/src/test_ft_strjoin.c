/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:09:10 by agaga             #+#    #+#             */
/*   Updated: 2024/11/01 18:57:06 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"

void test_ft_strjoin(char const *s1, char const *s2, char const *expected)
{
	char *result;

	result = ft_strjoin(s1, s2);
	if ((result == NULL && expected == NULL) || (result != NULL && expected != NULL 
		&& strcmp(result, expected) == 0)) 
	{
		printf("Test for: ft_strjoin(\"%s\", \"%s\") == \"%s\" "GREEN" PASS\n"RESET"", s1, s2, expected);
		pass_count++;
	} 
	else
	{
		printf("Test failed: ft_strjoin(\"%s\", \"%s\") == \"%s\", expected \"%s\" "RED"FAIL\n"RESET"", s1, s2, result ? result : "NULL", expected ? expected : "NULL");
		fail_count++;
	}
	free(result);
}

int main()
{
	test_ft_strjoin("Hello, ", "World!", "Hello, World!");  // Normal case
	test_ft_strjoin("Foo", "", "Foo");                      // Empty second string
	test_ft_strjoin("", "Bar", "Bar");                      // Empty first string
	test_ft_strjoin("", "", "");                            // Both strings empty
	test_ft_strjoin(NULL, "Hello", NULL);                   // First string NULL
	test_ft_strjoin("World", NULL, NULL);                   // Second string NULL
	test_ft_strjoin(NULL, NULL, NULL);                      // Both strings NULL

	if (fail_count == 0)
		return (0);
	else
	{
		printf(RED "%d tests failed out of %d\n" RESET, fail_count, pass_count + fail_count);
		return (1);
	}
}
