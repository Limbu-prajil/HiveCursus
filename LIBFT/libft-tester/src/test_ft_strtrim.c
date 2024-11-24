/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:31:16 by agaga             #+#    #+#             */
/*   Updated: 2024/11/08 20:13:53 by agaga            ###   ########.fr       */
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
		printf("Test %d: "RED" FAIL\n" RESET, iTest);
		fail_count++;
	}
    iTest++;
}

int main(void)
{
    printf("ft_strtrim tests:\n");

    char *s;

    s = ft_strtrim("   xxxtripouille", " xo");
    check(!strcmp(s, "tripouille"));
	printf(CYAN"Got %s\n"RESET, s);
    free(s);

    s = ft_strtrim("tripouille   xxx", " x");
    check(!strcmp(s, "tripouille"));
	printf(CYAN"got %s\n"RESET, s);
    free(s);

	s = ft_strtrim("xxxtripouillexxx", "x");
	check(!strcmp(s, "tripouille"));
	printf(CYAN"got %s\n"RESET, s);
	free(s);

    s = ft_strtrim("   xxx   xxx", " x");
    check(!strcmp(s, ""));
	printf(CYAN"got %s\n"RESET, s);
    free(s);

    s = ft_strtrim("", "123");
    check(!strcmp(s, ""));
	printf(CYAN"got %s\n"RESET, s);
    free(s);

    s = ft_strtrim("123", "");
    check(!strcmp(s, "123"));
	printf(CYAN"got %s\n"RESET, s);
    free(s);

    s = ft_strtrim("", "");
    check(!strcmp(s, ""));
	printf(CYAN"got %s\n"RESET, s);
    free(s);

    s = ft_strtrim("abcdba", "acb");
    check(!strcmp(s, "d"));
	printf(CYAN"got %s\n"RESET, s);
    free(s);

    printf("\n");
    
	      
	if (fail_count == 0)
		return (0);
	else 
		return (1);
}
