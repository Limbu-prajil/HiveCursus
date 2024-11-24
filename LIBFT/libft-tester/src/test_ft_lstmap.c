/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:01:14 by agaga             #+#    #+#             */
/*   Updated: 2024/11/11 16:45:45 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tester.h"

void *mod(void *content)
{
    char *str = ft_strdup((char *)content);
    for (int i = 0; str[i]; i++)
    {
        str[i] = ft_toupper(str[i]);
    }
    return str;
}

void del(void *content)
{
    free(content);
}

void test_ft_lstmap()
{
    t_list *list = ft_lstnew(ft_strdup("first"));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("second")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("third")));

    t_list *new_list = ft_lstmap(list, mod, del);

    t_list *current = new_list;
    int pass = 1;
    if (strcmp((char *)current->content, "FIRST") != 0) pass = 0;
    current = current->next;
    if (strcmp((char *)current->content, "SECOND") != 0) pass = 0;
    current = current->next;
    if (strcmp((char *)current->content, "THIRD") != 0) pass = 0;

    current = list;
    if (strcmp((char *)current->content, "first") != 0) pass = 0;
    current = current->next;
    if (strcmp((char *)current->content, "second") != 0) pass = 0;
    current = current->next;
    if (strcmp((char *)current->content, "third") != 0) pass = 0;

    if (pass)
    {
        printf("Test Passed: works correctly\n");
		pass_count++;
    }
    else
    {
        printf("Test Failed: does not work correctly\n");
		fail_count++;
    }
    ft_lstclear(&list, del);
    ft_lstclear(&new_list, del);
}

int main()
{
    test_ft_lstmap();
    if (fail_count == 0)
	{
		printf(GREEN""BOLD"Test Passed\n"RESET);
		return 0;
	}
	else
	{
		printf(RED"Test Failed\n"RESET);
		return 1;
	}
}