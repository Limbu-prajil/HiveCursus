/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:21:00 by agaga             #+#    #+#             */
/*   Updated: 2024/11/08 19:33:50 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../util/tester.h"

static void free_mem(char **str)
{
	size_t i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void test_ft_split(const char *s, char c, const char **expected)
{
    char **result = ft_split(s, c);
    int i = 0;
    int test_passed = 1;

    while (result[i] && expected[i])
    {
        if (strcmp(result[i], expected[i]) != 0)
        {
            test_passed = 0;
            break;
        }
        i++;
    }

    if (result[i] || expected[i])
        test_passed = 0;

    if (test_passed)
    {
        printf("Test for ft_split(\"%s\", '%c'): " GREEN "PASS\n" RESET, s, c);
	printf("Expected: " YELLOW);
        for (int j = 0; expected[j]; j++)
        {
            printf("\"%s\" ", expected[j]);
        }
        printf(RESET "\nGot: " BLUE);
        for (int j = 0; result[j]; j++)
        {
            printf("\"%s\" ", result[j]);
        }
        printf(RESET "\n");
        pass_count++;
    }
    else
    {
        printf("Test for ft_split(\"%s\", '%c'): " RED "FAIL\n" RESET, s, c);
		printf(RESET "\nGot: " BLUE);
        for (int j = 0; result[j]; j++)
        {
            printf("\"%s\" ", result[j]);
        }
        fail_count++;
    }
	free_mem(result);
}

int main()
{
    const char *test1[] = {"Hello", "World", NULL};
    const char *test2[] = {"42", "Network", "Project", NULL};
    const char *test3[] = {"One", NULL};
    const char *test4[] = {NULL};
    const char *test5[] = {"Boundary", NULL, NULL};

    test_ft_split("Hello World", ' ', test1);        // Normal case with space delimiter
    test_ft_split("42,Network,Project", ',', test2); // Multiple words with comma delimiter
    test_ft_split("One", ' ', test3);                // Single word, no delimiter
    test_ft_split("", ' ', test4);                   // Empty string
    test_ft_split("Boundary!!!!", '!', test5);           // No occurrence of delimiter


    if (fail_count == 0)
        return (0);
    else
    {
        printf(RED "%d tests failed out of %d\n" RESET, fail_count, pass_count + fail_count);
        return (1);
    }
}
