/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:42:18 by agaga             #+#    #+#             */
/*   Updated: 2024/11/03 17:22:13 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../util/tester.h"

void test_ft_strdup(const char *input, const char *expected) {
    char *result = ft_strdup(input);

    if ((result == NULL && expected == NULL) || 
        (result != NULL && strcmp(result, expected) == 0)) {
        printf("Test for ft_strdup(\"%s\"): "GREEN" PASS\n" RESET, input);
        pass_count++;
    } else {
        printf(RED "Test for ft_strdup(\"%s\"): FAIL\n" RESET, input);
        printf("Expected: \"%s\", got: \"%s\"\n", expected, result ? result : "NULL");
        fail_count++;
    }
    free(result);  // Free the allocated memory by ft_strdup
}

int main(void) {
    test_ft_strdup("Hello, World!", "Hello, World!");  // Normal case
    test_ft_strdup("42", "42");                          // Simple numeric string
    test_ft_strdup("", "");                               // Empty string
    test_ft_strdup("Testing ft_strdup", "Testing ft_strdup");  // Longer string
    test_ft_strdup("Hello, GitHub!", "Hello, GitHub!");  // New test case
    test_ft_strdup("1234567890", "1234567890");  // New test case
    test_ft_strdup("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz");  // New test case

	if (fail_count == 0)
		return (0);
	else
	{
		printf(RED "%d tests failed out of %d.\n" RESET, fail_count, pass_count + fail_count);
		return (1);
	}
}

