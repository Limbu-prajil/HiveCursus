#include "get_next_line.h"
#include <stdlib.h>

// Check if any node in the linked list contains a newline character.
int found_newline(t_list *list)
{
    int i;

    if (list == NULL) // If the list is empty, return false (0).
        return 0;

    // Iterate through the linked list.
    while (list)
    {
        i = 0;

        // Traverse the current buffer to look for a newline character.
        while (list->str_buf[i] && i < BUFFER_SIZE)
        {
            if (list->str_buf[i] == '\n') // If newline is found, return true (1).
                return 1;
            i++;
        }

        list = list->next; // Move to the next node.
    }

    return 0; // Return false if no newline is found in the entire list.
}

// Find the last node in the linked list.
t_list *find_last_node(t_list *list)
{
    if (list == NULL) // If the list is empty, return NULL.
        return NULL;

    // Traverse until the last node.
    while (list->next)
        list = list->next;

    return list; // Return the last node.
}

// Copy characters from the linked list into a string, stopping at a newline.
void copy_str(t_list *list, char *str)
{
    int i, k;

    if (list == NULL) // If the list is empty, return.
        return;

    k = 0; // Index for the destination string.

    // Iterate through the linked list.
    while (list)
    {
        i = 0;

        // Copy characters from the current buffer.
        while (list->str_buf[i])
        {
            if (list->str_buf[i] == '\n') // Stop at newline.
            {
                str[k++] = '\n';
                str[k] = '\0'; // Null-terminate the string.
                return;
            }

            str[k++] = list->str_buf[i++];
        }

        list = list->next; // Move to the next node.
    }

    str[k] = '\0'; // Null-terminate the string at the end of copying.
}

// Calculate the length of the string up to the first newline in the list.
int len_to_newline(t_list *list)
{
    int i, len = 0;

    if (list == NULL) // If the list is empty, return 0.
        return 0;

    // Iterate through the linked list.
    while (list)
    {
        i = 0;

        // Count characters in the current buffer.
        while (list->str_buf[i])
        {
            if (list->str_buf[i] == '\n') // Stop at newline.
            {
                len++;
                return len;
            }

            len++;
            i++;
        }

        list = list->next; // Move to the next node.
    }

    return len; // Return the total length.
}

// Free all nodes in the linked list and reset it for reuse.
void dealloc(t_list **list, t_list *clean_node, char *buf)
{
    t_list *tmp;

    if (*list == NULL) // If the list is already empty, return.
        return;

    // Iterate through the linked list and free each node.
    while (*list)
    {
        tmp = (*list)->next;
        free((*list)->str_buf); // Free the buffer in the current node.
        free(*list);           // Free the node itself.
        *list = tmp;           // Move to the next node.
    }

    *list = NULL; // Reset the list pointer.

    if (clean_node->str_buf[0]) // If clean_node's buffer is not empty.
        *list = clean_node;     // Retain clean_node in the list.
    else
    {
        free(buf);        // Free the buffer.
        free(clean_node); // Free the clean_node.
    }
}
