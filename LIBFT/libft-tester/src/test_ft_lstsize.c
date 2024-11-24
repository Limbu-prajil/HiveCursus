/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:03:15 by agaga             #+#    #+#             */
/*   Updated: 2024/11/08 19:40:23 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tester.h"


static t_list *nodescreator(void)
{
    t_list *node1 = ft_lstnew("First");
    t_list *node2 = ft_lstnew("Second");
    t_list *node3 = ft_lstnew("Third");
    t_list *node4 = ft_lstnew("Fourth");

    if (node1) node1->next = node2;
    if (node2) node2->next = node3;
    if (node3) node3->next = node4;

    return (node1);
}
static t_list *nodescreator1(void)
{
    t_list *node1 = ft_lstnew("First");
    t_list *node2 = ft_lstnew("Second");
    t_list *node3 = ft_lstnew("Third");
    t_list *node4 = ft_lstnew("Fourth");
	t_list *node5 = ft_lstnew("Fifth");

    if (node1) node1->next = node2;
    if (node2) node2->next = node3;
    if (node3) node3->next = node4;
	if (node4) node4->next = node5;

    return (node1);
}

static void comp(t_list *head, int expected)
{
    int size = ft_lstsize(head);
    printf("Expected size: %d, Actual size: %d\n", expected, size);
    
	if (size == expected)
	{
        printf(GREEN"Test passed!\n"RESET);
		pass_count++;
	}
    else
    {
		printf(RED"Test failed \n"RESET);
		fail_count++;
	}
}
void free_mem(t_list *head)
{
	if (head == NULL)
		return ;
	free_mem(head->next);
	free(head);
}

int main(void)
{
    t_list *head = nodescreator();
	t_list *head1 = nodescreator1();


    comp(head, 4);
	comp(head1, 5);
	
	free_mem(head);
	free_mem(head1);

	if (fail_count == 0)
		return (0);
	else
	{
		printf("%d out for %d tests failed.\n", fail_count, pass_count + fail_count);
		return (1);
	}
}
