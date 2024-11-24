/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstdelone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:17:58 by agaga             #+#    #+#             */
/*   Updated: 2024/11/11 15:36:52 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include "libft.h"


void test_ft_lstdelone()
{
    t_list *list = ft_lstnew(ft_strdup("Single Element"));

    printf(BOLD BLUE"List before deletion:\n"RESET);
    if (list != NULL)
    {
        printf("%s\n", (char *)list->content);
    }

    ft_lstdelone(list, free);
	list = NULL;

    printf(BOLD BLUE"List after deletion:\n"RESET);
    if (list == NULL)
    {
        printf("List is empty\n");
		pass_count++;
    }
    else
    {
        printf("List is not empty\n");
		fail_count++;
    }
}

int main()
{
    test_ft_lstdelone();
	
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