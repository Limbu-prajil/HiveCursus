/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:17:02 by agaga             #+#    #+#             */
/*   Updated: 2024/11/03 19:56:51 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"


void test_ft_strlcat(const char *dst, const char *src, size_t size, const char *expected, size_t expected_length) 
{
    char buffer[100];
    strncpy(buffer, dst, sizeof(buffer));

    size_t result = ft_strlcat(buffer, src, size);

    if (strcmp(buffer, expected) == 0 && result == expected_length) {
        printf("Test for ft_strlcat(dst=\"%s\", src=\"%s\", size=%zu):"GREEN" PASS\n" RESET, dst, src, size);
        pass_count++;
    } else {
        printf("Test for ft_strlcat(dst=\"%s\", src=\"%s\", size=%zu): "RED"FAIL\n" RESET, dst, src, size);
        printf("Expected: \"%s\", got: \"%s\"\n", expected, buffer);
        printf("Expected length: %zu, got: %zu\n", expected_length, result);
        fail_count++;
    }
}

int main(void) {
    // Normal case
    test_ft_strlcat("Hello, ", "World!", 15, "Hello, World!", 13);  // Fits within size
    test_ft_strlcat("Hello, ", "World!", 10, "Hello, Wo", 13);        // Truncated

    // Edge cases
    test_ft_strlcat("", "World!", 15, "World!", 6);                   // Empty dst
    test_ft_strlcat("Hello", "", 15, "Hello", 5);                     // Empty src
    test_ft_strlcat("", "", 15, "", 0);                               // Both empty

    // Case where dst is not large enough
    test_ft_strlcat("Hello", "World!", 5, "Hello", 11);               // Not enough space, returns length of "HelloWorld!"

	if (fail_count == 0)
		return (0);
	else 
	{
		printf(RED "%d tests failed out of %d.\n" RESET, fail_count, pass_count + fail_count);
		return (1);
	}

}
