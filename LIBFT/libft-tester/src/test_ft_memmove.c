/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:22:22 by agaga             #+#    #+#             */
/*   Updated: 2024/11/07 15:16:49 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"

int gpass_count = 0;
int gfail_count = 0;

void test_ft_memmove(char *input, size_t dest_offset, size_t src_offset, size_t len) 
{
    char buffer1[100];
    char buffer2[100];

    memset(buffer1, 0, sizeof(buffer1));
    memset(buffer2, 0, sizeof(buffer2));
    
    strncpy(buffer1, input, sizeof(buffer1) - 1);
    strncpy(buffer2, input, sizeof(buffer2) - 1);

    char *result = ft_memmove(buffer1 + dest_offset, buffer1 + src_offset, len);
    char *expected = memmove(buffer2 + dest_offset, buffer2 + src_offset, len);

    buffer1[dest_offset + len] = '\0';
    buffer2[dest_offset + len] = '\0';

    if (memcmp(result, expected, len) == 0) 
    {
        printf("Test for: ft_memmove(\"%s\", %zu, %zu, %zu) == \"%s\" " GREEN "PASS\n" RESET, input, dest_offset, src_offset, len, result);
        gpass_count++;
    } 
    else 
    {
        printf("Test for: ft_memmove(\"%s\", %zu, %zu, %zu) == \"%s\", expected \"%s\" " RED "FAIL\n" RESET, input, dest_offset, src_offset, len, result, expected);
        gfail_count++;
    }
}

int main(void)
{
    test_ft_memmove("Hello, World!", 0, 7, 6);       // Normal case
    test_ft_memmove("abcdef", 2, 0, 3);              // Overlapping, forward
    test_ft_memmove("123456789", 0, 4, 5);           // Overlapping, backward
    test_ft_memmove("Test string", 5, 5, 5);         // Same source and destination
    test_ft_memmove("Sample text", 3, 8, 4);         // Partial overlap
    test_ft_memmove("Another test", 0, 0, 0);        // Zero length
	test_ft_memmove("Overlap test", 3, 0, 10);       // Overlapping, forward
	test_ft_memmove("Overlap test", 0, 3, 10);       // Overlapping, backward
	test_ft_memmove("Edge case test", 5, 5, 10);     // Overlapping, same start
	test_ft_memmove("Edge case test", 0, 5, 5);      // Overlapping, partial forward
	test_ft_memmove("Edge case test", 5, 0, 5);      // Overlapping, partial backward
	
    if (gfail_count == 0) 
        return (0);
    else 
    {
        printf(RED "%d tests failed out of %d\n" RESET, gfail_count, gpass_count + gfail_count);
        return (1);
    }
}

