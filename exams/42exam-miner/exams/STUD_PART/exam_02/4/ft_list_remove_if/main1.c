#include <stdio.h>
#include <stdlib.h>

typedef struct s_list t_list;
struct s_list {
    void *data;
    t_list *next;
};

void printlist(t_list *lst)
{
    while (lst)
    {
        printf("%s ", (char *)lst->data);
        lst = lst->next;
    }
}

int equal(void *a, void *b)
{
    return (a == b ? 0 : 1);
}

void ft_list_remove_if(t_list **begin, void *dref, int (*cmp)())
{
    t_list *tmp = NULL;
    while (*begin)
    {
        if (((int (*)(void *, void *))cmp)((*begin)->data, dref) == 0)
        {
            tmp = *begin;
            *begin = (*begin)->next;
            free(tmp);
        }
        else
            begin = &((*begin)->next);
    }
}

int main(void)
{
    t_list *a = malloc(sizeof(t_list));
    t_list *b = malloc(sizeof(t_list));
    t_list *c = malloc(sizeof(t_list));
    t_list *d = malloc(sizeof(t_list));
    a->data = "sa";
    a->next = b;
    b->data = "sb";
    b->next = c;
    c->data = "sc";
    c->next = d;
    d->data = "sd";
    d->next = NULL;
    
    printlist(a);
    printf("\n");
    ft_list_remove_if(&a, "sc", equal);
    printlist(a);
    printf("\n");
    
    return (0);
}
