/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:59:46 by agaga             #+#    #+#             */
/*   Updated: 2024/11/08 19:23:49 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tester.h"

static void test_ft_lstnew(char *content, char *expected)
{
	t_list *node;

	node = ft_lstnew(content);
	
    if (node && (content == expected))
	{
        printf("Node content: "CYAN" %s\n" RESET, (char *)node->content);
		printf("expected: "GREEN"%s\n"RESET, expected);
		pass_count++;
	}
    else
	{
        printf(RED"Node is NULL, failed to create a new node.\n"RESET);
		fail_count++;
	}
	if (node)
		free(node);
}

int main()
{
    test_ft_lstnew("Heyehey", "Heyehey");
	test_ft_lstnew("1234", "1234");
	test_ft_lstnew(NULL, NULL);

	if (fail_count == 0)
		return (0);
	else
	{
		printf(RED"%d out of %d failed."RESET, fail_count, pass_count + fail_count);
		return (1);
	}
}
