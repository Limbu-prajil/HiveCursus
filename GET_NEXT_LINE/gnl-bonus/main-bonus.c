#include "./get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
    // Open multiple file descriptors
    int fd1 = open("./example1.txt", O_RDONLY);
    int fd2 = open("./example2.txt", O_RDONLY);
    int fd3 = open("./example3.txt", O_RDONLY);
    char *line;

    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        printf("Error opening files\n");
        return (1);
    }

    // Read lines alternately from each file descriptor
    for (int i = 0; i < 10; i++) // Adjust the loop count as needed
    {
        // Read from fd1
        line = get_next_line(fd1);
        if (line)
        {
            printf("FD1: %s", line);
            free(line);
        }

        // Read from fd2
        line = get_next_line(fd2);
        if (line)
        {
            printf("FD2: %s", line);
            free(line);
        }

        // Read from fd3
        line = get_next_line(fd3);
        if (line)
        {
            printf("FD3: %s", line);
            free(line);
        }
    }

    // Close all file descriptors
    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
}
