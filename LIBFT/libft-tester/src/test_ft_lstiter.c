/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstiter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:37:25 by agaga             #+#    #+#             */
/*   Updated: 2024/11/11 15:45:39 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tester.h"

static void mod(void *content)
{
    char *str = (char *)content;
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

void test_ft_lstiter()
{
    t_list *list = ft_lstnew(strdup("first"));
    ft_lstadd_back(&list, ft_lstnew(strdup("second")));
    ft_lstadd_back(&list, ft_lstnew(strdup("third")));

    ft_lstiter(list, mod);

    t_list *current = list;
    int pass = 1;
    while (current != NULL)
    {
        if (strcmp((char *)current->content, "FIRST") != 0 &&
            strcmp((char *)current->content, "SECOND") != 0 &&
            strcmp((char *)current->content, "THIRD") != 0)
        {
            pass = 0;
            break;
        }
        current = current->next;
    }

    if (pass)
    {
        printf(GREEN"Test Passed\n"RESET);
		pass_count++;
    }
    else
    {
        printf(RED"Test Failed\n"RESET);
		fail_count++;
    }

    ft_lstclear(&list, free);
}

int main()
{
    test_ft_lstiter();
	
    if (fail_count == 0)
	{
		printf(GREEN"Test Passed\n"RESET);
		return 0;
	}
	else
	{
		printf(RED"Test Failed\n"RESET);
		return 1;
	}
}