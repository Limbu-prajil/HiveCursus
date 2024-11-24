/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:33:41 by agaga             #+#    #+#             */
/*   Updated: 2024/11/11 15:07:11 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tester.h"

void test_ft_lstadd_back()
{
    t_list *list = ft_lstnew(strdup("First"));
    t_list *new2 = ft_lstnew(strdup("Second"));
    t_list *new3 = ft_lstnew(strdup("Third"));

    ft_lstadd_back(&list, new2);
    ft_lstadd_back(&list, new3);

    printf(CYAN"List after adding elements:\n"RESET);
    t_list *node = list;
	while (node != NULL)
	{
    	printf("%s\n", (char *)node->content);
	    node = node->next;
		pass_count++;
	}
	ft_lstclear(&list, free);
	
}

// Main function
int main()
{
    test_ft_lstadd_back();

    if (pass_count == 3)
	{
		printf(GREEN"Test passed\n"RESET);
		return (0);
	}
	else
	{
		printf(RED"Test failed\n"RESET);
		return (1);
	}
	
}
