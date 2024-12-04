#include "./get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("./example.txt", O_RDONLY); // Open file for reading
	char *line;

	while ((line = get_next_line(fd)) != NULL) // Loop until all lines are read
	{
		printf("%s", line); // Print each line
		free(line);         // Free the memory allocated for the line
	}

	close(fd); // Close the file
	return 0;
}
