/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:11:08 by agaga             #+#    #+#             */
/*   Updated: 2024/11/03 14:44:16 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"

void test_ft_memcpy(const char *src, size_t len)
{
    char std_dest[50] = {0};
    char ft_dest[50] = {0};

    memcpy(std_dest, src, len);
    ft_memcpy(ft_dest, src, len);

    if (ft_memcmp(std_dest, ft_dest, len) == 0)
    {
        printf("Test for ft_memcpy(\"%s\", %zu): " GREEN "PASS\n" RESET, src, len);
        pass_count++;
    }
    else
    {
        printf("Test for ft_memcpy(\"%s\", %zu): " RED "FAIL\n" RESET, src, len);
        fail_count++;
    }
}

int main()
{
    test_ft_memcpy("Hello, World!", 13); // Standard case
    test_ft_memcpy("Testing123", 5);     // Partial copy
    test_ft_memcpy("42Network", 9);      // Exact length copy
    test_ft_memcpy("Boundary", 0);       // Zero length copy
    test_ft_memcpy("", 1);               // Empty string

    if (fail_count == 0)
        return (0);
    else
    {
        printf(RED "%d tests failed out of %d\n" RESET, fail_count, pass_count + fail_count);
        return (1);
    }
}
