#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    t_list *node1 = (t_list *)malloc(sizeof(t_list));
    t_list *node2 = (t_list *)malloc(sizeof(t_list));
    t_list *node3 = (t_list *)malloc(sizeof(t_list));
    node1->content = "Content1";
    node1->next = node2;
    node2->content = "Content2";
    node2->next = node3;
    node3->content = "Content3";
    node3->next = NULL;

    t_list *last = ft_lstlast(node1);

    if (last != NULL)
    {
        printf("Test Passed: Last element is correct\n");
	printf("last content is: %s\n", (char *)last->content);
    }
}

int main()
{
    test_ft_lstlast();
    return (0);
}
