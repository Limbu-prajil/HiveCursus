#include "./get_next_line.h"
#include <stdio.h>

int main()
{
	int fd = open("./example.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("* %s", line);
		free(line);
	}

	close(fd);
	return 0;
}
