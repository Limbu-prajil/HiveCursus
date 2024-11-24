/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:08:56 by agaga             #+#    #+#             */
/*   Updated: 2024/11/06 20:31:46 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"


void test_ft_strncmp(const char *s1, const char *s2, size_t n)
{

    int result = ft_strncmp(s1, s2, n);
    int expected = strncmp(s1, s2, n);

    if (result == expected)
    {
        printf("Test for strncmp: " GREEN "PASS\n" RESET);
		printf("Expected: \"%d\", got: \"%d\"\n", expected, result);
        pass_count++;
    }
    else
    {
        printf("Test for strncmp: " RED "FAIL\n" RESET);
		printf("Expected: \"%d\", got: \"%d\"\n", expected, result);
        fail_count++;
    }
}

int main(void)
{

    test_ft_strncmp("helloo", "helloo", 5);
    test_ft_strncmp("hello", "world", 5);
    test_ft_strncmp("hello", "hell", 4);
    test_ft_strncmp("hello", "hella", 5);
    test_ft_strncmp("hello", "hellz", 5);

	if (fail_count == 0)
		return (0);
	else
	{
		printf(RED "%d tests failed out of %d\n" RESET, fail_count, pass_count + fail_count);
		return (1);
	}
}
