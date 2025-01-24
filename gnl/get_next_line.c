#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

// Prepare the list for the next call by removing processed nodes.
void polish_list(t_list **list)
{
    t_list *last_node, *clean_node;
    int i, k;
    char *buf;

    buf = malloc(BUFFER_SIZE + 1); // Allocate memory for the buffer.
    clean_node = malloc(sizeof(t_list)); // Allocate memory for a new node.

    if (buf == NULL || clean_node == NULL) // If allocation fails, return.
        return;

    last_node = find_last_node(*list); // Find the last node in the list.

    i = 0; // Find the position of the first newline in the last node's buffer.
    while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
        i++;

    k = 0; // Copy characters after the newline into the new buffer.
    while (last_node->str_buf[i] && last_node->str_buf[++i])
        buf[k++] = last_node->str_buf[i];

    buf[k] = '\0'; // Null-terminate the new buffer.

    clean_node->str_buf = buf; // Assign the buffer to the new node.
    clean_node->next = NULL;

    dealloc(list, clean_node, buf); // Free the old list and retain the new node.
}

// Extract a line from the linked list.
char *get_line(t_list *list)
{
    int str_len;
    char *next_str;

    if (list == NULL) // If the list is empty, return NULL.
        return NULL;

    str_len = len_to_newline(list); // Calculate the length of the next line.

    next_str = malloc(str_len + 1); // Allocate memory for the string.

    if (next_str == NULL) // If allocation fails, return NULL.
        return NULL;

    copy_str(list, next_str); // Copy the line into the allocated string.

    return next_str; // Return the extracted line.
}

// Append a new buffer to the end of the linked list.
void append(t_list **list, char *buf)
{
    t_list *new_node, *last_node;

    last_node = find_last_node(*list); // Find the last node in the list.

    new_node = malloc(sizeof(t_list)); // Allocate memory for the new node.

    if (new_node == NULL) // If allocation fails, return.
        return;

    if (last_node == NULL) // If the list is empty, the new node becomes the head.
        *list = new_node;
    else
        last_node->next = new_node; // Otherwise, append it to the end.

    new_node->str_buf = buf; // Assign the buffer to the new node.
    new_node->next = NULL;   // Initialize the next pointer to NULL.
}

// Populate the linked list with data from the file.
void create_list(t_list **list, int fd)
{
    int char_read;
    char *buf;

    while (!found_newline(*list)) // Continue until a newline is found.
    {
        buf = malloc(BUFFER_SIZE + 1); // Allocate memory for the buffer.

        if (buf == NULL) // If allocation fails, return.
            return;

        char_read = read(fd, buf, BUFFER_SIZE); // Read data from the file into buf.

        if (char_read <= 0) // If EOF or error, free buffer and return.
        {
            free(buf);
            return;
        }

        buf[char_read] = '\0'; // Null-terminate the buffer.

        append(list, buf); // Append the buffer to the linked list.
    }
}

// Main function to extract the next line from the file.
char *get_next_line(int fd)
{
    static t_list *list; // Static variable to persist the linked list.
    char *next_line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
	return (NULL);
  
    create_list(&list, fd); // Populate the list with data.

    if (list == NULL) // If the list is empty, return NULL.
        return NULL;

    next_line = get_line(list); // Extract the next line.

    polish_list(&list); // Prepare the list for the next call.

    return next_line; // Return the extracted line.
}
