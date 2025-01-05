#include "./get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
    // Open multiple file descriptors
    int fd3 = open("./example.txt", O_RDONLY);
    int fd4 = open("./example1.txt", O_RDONLY);
    int fd5 = open("./example2.txt", O_RDONLY);
    printf("%d %d %d\n", fd3, fd4, fd5);
    char *line;

    if (fd3 < 0 || fd4 < 0 || fd5 < 0)
    {
        printf("Error opening files\n");
        return (1);
    }

    // Read lines alternately from each file descriptor
    for (int i = 0; i < 11; i++) // Adjust the loop count as needed
    {
        // Read from fd3
        line = get_next_line(fd3);
        if (line)
        {
            printf("FD3: %s", line);
            free(line);
        }

        // Read from fd4
        line = get_next_line(fd4);
        if (line)
        {
            printf("FD4: %s", line);
            free(line);
        }

        // Read from fd5
        line = get_next_line(fd5);
        if (line)
        {
            printf("FD5: %s", line);
            free(line);
        }
    }

    // Close all file descriptors
    close(fd3);
    close(fd4);
    close(fd5);

    return 0;
}
