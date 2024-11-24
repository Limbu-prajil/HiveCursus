/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:34:09 by agaga             #+#    #+#             */
/*   Updated: 2024/11/03 16:41:58 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../util/tester.h"

void test_ft_strchr(const char *s, int c, const char *expected)
{
    char *result = ft_strchr(s, c);
    
    if ((result == NULL && expected == NULL) || (result != NULL && strcmp(result, expected) == 0)) {
        printf("Test for ft_strchr(\"%s\", '%c'): " GREEN "PASS\n" RESET, s, c);
        pass_count++;
    } else {
        printf("Test failed: ft_strchr(\"%s\", '%c') == \"%s\", expected \"%s\" " RED "FAIL\n" RESET, s, c, result ? result : "NULL", expected ? expected : "NULL");
        fail_count++;
    }
}

int main(void)
{
    test_ft_strchr("Hello, World!", 'W', "World!");         // Test with normal case
    test_ft_strchr("42 is the answer", '4', "42 is the answer"); // Test with numeric character
    test_ft_strchr("Boundary case", 'B', "Boundary case");   // Test with uppercase character
    test_ft_strchr("Boundary case", 'b', strchr("Boundary case", 'b'));              // Test with a character not in string
    test_ft_strchr("Find the end", 'e', strchr("Find the end", 'e'));              // Test with character at the end
    test_ft_strchr("", 'a', NULL);                           // Test with empty string

    if (fail_count == 0)
        return (0);
    else
    {
        printf(RED "%d tests failed out of %d\n" RESET, fail_count, pass_count + fail_count);
        return (1);
    }
}
