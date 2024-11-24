/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:27:34 by agaga             #+#    #+#             */
/*   Updated: 2024/11/06 19:53:41 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"

char to_uppercase(unsigned int i, char c) 
{
    (void)i;
    return ft_toupper(c);
}

char to_lowercase(unsigned int i, char c) 
{
    (void)i;
    return ft_tolower(c);
}

void test_ft_strmapi(char *str, char *expected, char (*f)(unsigned int, char)) 
{
	char *result = ft_strmapi(str, f);

	if (strcmp(result, expected) == 0) 
	{
		printf("Test for '%s' "GREEN"\tPASS\n" RESET, str);
		printf("Expected '%s' got '%s' \n", expected, result);
		pass_count++;
	}
	else
	{
		printf("Test for '%s' "RED"\tFAiL\n" RESET, str);
		printf("Expected '%s' got '%s' \n", expected, result);
		fail_count++;
	}
	free(result);
}

int main(void) 
{

    test_ft_strmapi("hello", "HELLO", to_uppercase);
    test_ft_strmapi("world", "WORLD", to_uppercase);
    test_ft_strmapi("12345", "12345", to_uppercase);
    test_ft_strmapi("", "", to_uppercase);


    test_ft_strmapi("HELLO", "hello", to_lowercase);
    test_ft_strmapi("WORLD", "world", to_lowercase);
    test_ft_strmapi("12345", "12345", to_lowercase);
    test_ft_strmapi("", "", to_lowercase);

	if (fail_count == 0)
		return (0);
	else
	{
		printf(RED"%d tes out of %d failed\n"RESET, fail_count, pass_count + fail_count);
		return (1);
	}
}
