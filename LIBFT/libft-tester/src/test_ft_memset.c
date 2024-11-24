/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:27:11 by agaga             #+#    #+#             */
/*   Updated: 2024/11/01 18:56:29 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../util/tester.h"


void test_ft_memset(char *input, int c, size_t len, char *expected_output) 
{
    char buffer[100];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    char *result = ft_memset(buffer, c, len);

	if (memcmp(result, expected_output, len) == 0) 
	{
		printf("Test for: ft_memset(\"%s\", %d, %zu) == \"%s\" " GREEN "PASS\n" RESET, input, c, len, buffer);
		pass_count++;
	} 
	else 
	{
		printf("Test for: ft_memset(\"%s\", %d, %zu) == \"%s\", expected \"%s\" " RED "FAIL\n" RESET, input, c, len, buffer, expected_output);
		fail_count++;
	}
}

int main(void)
{
    char expected1[100] = "xxxxxghij";
    memset(expected1, 'x', 5);
    test_ft_memset("abcdefghij", 'x', 5, expected1);

    char expected2[100] = "aaaaajklm";
    memset(expected2, 'a', 5);
    test_ft_memset("azertyghghghg", 'a', 5, expected2);

    char expected3[100] = "zzzzzzzzz";
    memset(expected3, 'z', 10);
    test_ft_memset("abcdefghij", 'z', 10, expected3);

    if (fail_count == 0) 
        return (0);
    else 
    {
        printf(RED "%d tests failed out of %d\n" RESET, fail_count, pass_count + fail_count);
        return (1);
    }
}
