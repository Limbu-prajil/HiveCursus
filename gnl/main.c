#include "./get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    // Open the file
    //int fd = open("./example2.txt", O_RDONLY);
    int fd = 4;
    if (fd < 0) // Check if file opening failed
    {
        perror("Error opening file!");
        return (1);
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
     printf("%s", line);
     free(line);
    }
    if (NULL == line)
    {
    	perror("EOF or Error reading file!");
    	close(fd);
    	return (1);
    }
    return (0);
}

