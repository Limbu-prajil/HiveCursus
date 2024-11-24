/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:45:47 by agaga             #+#    #+#             */
/*   Updated: 2024/11/11 15:53:53 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tester.h"

void test_ft_lstadd_front()
{
    t_list *list = ft_lstnew(strdup("second"));
    t_list *new_elem = ft_lstnew(strdup("first"));

    ft_lstadd_front(&list, new_elem);

    if (list == new_elem && strcmp((char *)list->content, "first") == 0)
    {
        printf(GREEN"New element added to the front successfully\n"RESET);
		pass_count++;
    }
    else
    {
        printf(RED"Failed to add new element to the front\n"RESET);
		fail_count++;
    }

    if (list->next != NULL && strcmp((char *)list->next->content, "second") == 0)
    {
        printf(GREEN"Original first element is now the second element\n"RESET);
		pass_count++;	
    }
    else
    {
        printf(RED"Failed to update the list correctly\n"RESET);
		fail_count++;
    }

    ft_lstclear(&list, free);
}

int main()
{
    test_ft_lstadd_front();
	
    if (fail_count == 0)
	{
		printf(GREEN""BOLD"PASS\n"RESET);
		return 0;
	}
	else
	{
		printf(RED"FAIL\n"RESET);
		return 1;
	}
}