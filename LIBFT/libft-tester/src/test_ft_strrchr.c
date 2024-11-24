/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:03:48 by agaga             #+#    #+#             */
/*   Updated: 2024/11/04 22:16:06 by agaga            ###   ########.fr       */
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
    printf("ft_strrchr tests:\n");

    char s[] = "tripouille";
    char s2[] = "ltripouiel";
    char s3[] = "";
    
    check(ft_strrchr(s, 't') == s);
    check(ft_strrchr(s, 'l') == s + 8);
    check(ft_strrchr(s2, 'l') == s2 + 9);
    check(ft_strrchr(s, 'z') == NULL);
    check(ft_strrchr(s, 0) == s + strlen(s));
    check(ft_strrchr(s, 't' + 256) == s);
    char *empty = calloc(1, 1);
    check(ft_strrchr(empty, 'V') == NULL);
    free(empty);
    check(ft_strrchr(s3, 0) == s3);

    printf("\n");
      
	if (fail_count == 0)
		return (0);
	else 
		return (1);
}
