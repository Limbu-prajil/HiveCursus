/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:59:24 by agaga             #+#    #+#             */
/*   Updated: 2024/11/11 17:26:42 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"

int	pass = 1;

void test_strlcpy() {
    char dst[100];
    const char* src;
    size_t result;

    src = "Hello, world!";
    memset(dst, 0, sizeof(dst));
    result = ft_strlcpy(dst, src, sizeof(dst));
    assert(strcmp(dst, src) == 0);
    assert(result == strlen(src));
    printf("%sTest 1 passed%s\n", GREEN, RESET); pass = 0;

    // Test 2: Truncate the string
    src = "This is a long string that needs to be truncated";
    memset(dst, 0, sizeof(dst));
    result = ft_strlcpy(dst, src, 10);
    assert(strncmp(dst, src, 9) == 0);
    assert(dst[9] == '\0');
    assert(result == strlen(src));
    printf("%sTest 2 passed%s\n", GREEN, RESET); pass = 0;

    // Test 3: Copy an empty string
    src = "";
    memset(dst, 0, sizeof(dst));
    result = ft_strlcpy(dst, src, sizeof(dst));
    assert(strcmp(dst, src) == 0);
    assert(result == 0);
    printf("%sTest 3 passed%s\n", GREEN, RESET); pass = 0;

    // Test 4: Destination size is 0
    src = "This string should not be copied";
    memset(dst, 0, sizeof(dst));
    result = ft_strlcpy(dst, src, 0);
    assert(dst[0] == '\0');
    assert(result == strlen(src));
    printf("%sTest 4 passed%s\n", GREEN, RESET); pass = 0;

    // Test 5: Null source string
    src = NULL;
    memset(dst, 0, sizeof(dst));
    result = ft_strlcpy(dst, src, sizeof(dst));
    assert(dst[0] == '\0');
    assert(result == 0);
    printf("%sTest 5 passed%s\n", GREEN, RESET); pass = 0;

    printf("All tests passed!\n");
}

int main() {
    test_strlcpy();
    if (pass == 0)
		return 0;
	else
		return 1;
}
