/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:16:13 by agaga             #+#    #+#             */
/*   Updated: 2024/11/04 20:40:24 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../util/tester.h"

void check(bool condition)
{
    if (condition)
	{
        printf("Test %d: "GREEN" PASS\n" RESET, iTest);
		pass_count++;
	}
	else
	{
		printf("Test %d: "RED"FAIL\n" RESET, iTest);
		fail_count++;
	}
    iTest++;
}

int main()
{
    printf("ft_strnstr tests:\n");

    char haystack[30] = "aaabcabcd";
    char needle[10] = "aabc";
    char *empty = "";

    check(ft_strnstr(haystack, needle, 0) == NULL);
    check(ft_strnstr(haystack, needle, (size_t)-1) == haystack + 1);
    check(ft_strnstr(haystack, "a", (size_t)-1) == haystack);
    check(ft_strnstr(haystack, "c", (size_t)-1) == haystack + 4);
    check(ft_strnstr(empty, "", (size_t)-1) == empty);
    check(ft_strnstr(empty, "", 0) == empty);
    check(ft_strnstr(empty, "coucou", (size_t)-1) == NULL);
    check(ft_strnstr(haystack, "aaabc", 5) == haystack);
    check(ft_strnstr(empty, "12345", 5) == NULL);
    check(ft_strnstr(haystack, "abcd", 9) == haystack + 5);
    check(ft_strnstr(haystack, "cd", 8) == NULL);
    check(ft_strnstr(haystack, "a", 1) == haystack);
    check(ft_strnstr("1", "a", 1) == NULL);
    check(ft_strnstr("22", "b", 2) == NULL);

    printf("\n");
      
	if (fail_count == 0)
		return (0);
	else 
		return (1);
}
