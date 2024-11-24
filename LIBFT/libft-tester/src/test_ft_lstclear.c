/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstclear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:08:18 by agaga             #+#    #+#             */
/*   Updated: 2024/11/11 15:17:02 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tester.h"

void test_ft_lstclear()
{
    t_list *list = ft_lstnew(strdup("First"));
    t_list *new2 = ft_lstnew(strdup("Second"));
    t_list *new3 = ft_lstnew(strdup("Third"));
	t_list *new4 = ft_lstnew(strdup("Forth"));

    ft_lstadd_back(&list, new2);
    ft_lstadd_back(&list, new3);
	ft_lstadd_back(&list, new4);

    printf(BOLD BLUE "List before clearing:\n"RESET);
    t_list *node = list;
    while (node != NULL)
    {
        printf("%s\n", (char *)node->content);
        node = node->next;
    }

    ft_lstclear(&list, free);  

    printf(BOLD BLUE"List after clearing:\n"RESET);
    if (list == NULL)
    {
        printf("List is empty\n");
		pass_count++;
    }
    else
    {
        node = list;
        while (node != NULL)
        {
            printf("%s\n", (char *)node->content);
            node = node->next;
			fail_count++;
        }
    }
}

int main()
{
    test_ft_lstclear();

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