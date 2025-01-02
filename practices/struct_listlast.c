#include <stdio.h>
#include <string.h>

typedef struct s_list {
	void	*content;
	struct s_list	*next;
} t_list;

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!lst->next)
			last = lst;
		lst = lst->next;
	}
	return (last);
}

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
