#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{

    t_list *tmp;

    //int (*compare)(void *, void *) = (int (*)(void *, void *))cmp;
    while (*begin_list)
    {

        if (((int (*)(void *, void *))cmp)((*begin_list)->data, data_ref) == 0)
        {
            tmp = *begin_list;
            *begin_list = (*begin_list)->next;
            free(tmp);
        }
        else
            begin_list = &(*begin_list)->next;
    }
}
