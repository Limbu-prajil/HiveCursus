/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstlast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:56:37 by agaga             #+#    #+#             */
/*   Updated: 2024/11/11 16:01:08 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tester.h"

void test_ft_lstlast()
{
    t_list *list = ft_lstnew(strdup("first"));
    ft_lstadd_back(&list, ft_lstnew(strdup("second")));
    ft_lstadd_back(&list, ft_lstnew(strdup("third")));

    t_list *last = ft_lstlast(list);

    if (last != NULL && strcmp((char *)last->content, "third") == 0)
    {
        printf(GREEN"Test Passed: Last element is correct\n"RESET);
		printf("last element is: %s\n", (char *)last->content);
		pass_count++;
    }
    else
    {
        printf(RED"Test Failed: Last element is incorrect\n"RESET);
		fail_count++;
    }
    ft_lstclear(&list, free);
}

int main()
{
    test_ft_lstlast();
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