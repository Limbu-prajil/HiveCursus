/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:28:35 by agaga             #+#    #+#             */
/*   Updated: 2024/11/06 19:48:53 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../util/tester.h"

void to_uppercase(unsigned int i, char *c) 
{
    (void)i;
    *c = ft_toupper(*c);
}

void to_lowercase(unsigned int i, char *c) 
{
    (void)i;
    *c = ft_tolower(*c);
}

void test_ft_striteri(char *str, char *expected, void (*f)(unsigned int, char *)) 
{
	char strc[100];

	strcpy(strc, str);
	ft_striteri(strc, f);
	if (strcmp(strc, expected) == 0) 
	{
		printf("Test for '%s' "GREEN"\tPASS\n" RESET, str);
		printf("Expected '%s' got '%s' \n", expected, strc);
		pass_count++;
	}
	else
	{
		printf("Test for '%s' "RED"\tFAiL\n" RESET, str);
		printf("Expected '%s' got '%s' \n", expected, strc);
		fail_count++;
	}
}

int main(void) 
{

    test_ft_striteri("hello", "HELLO", to_uppercase);
    test_ft_striteri("world", "WORLD", to_uppercase);
    test_ft_striteri("12345", "12345", to_uppercase);
    test_ft_striteri("", "", to_uppercase);


    test_ft_striteri("HELLO", "hello", to_lowercase);
    test_ft_striteri("WORLD", "world", to_lowercase);
    test_ft_striteri("12345", "12345", to_lowercase);
    test_ft_striteri("", "", to_lowercase);

	if (fail_count == 0)
		return (0);
	else
	{
		printf(RED"%d tes out of %d failed\n"RESET, fail_count, pass_count + fail_count);
		return (1);
	}
}
