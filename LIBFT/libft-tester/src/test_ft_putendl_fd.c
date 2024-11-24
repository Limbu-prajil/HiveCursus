/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putendl_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:38:29 by agaga             #+#    #+#             */
/*   Updated: 2024/11/06 17:55:50 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../util/tester.h"

void test_ft_putendl_fd(char *str)
{
	int fd;
	char buffer[300];
	char expected[300];
	ssize_t bytes_read;

	fd = open("test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Error opening file");
		return;
	}
	ft_putendl_fd(str, fd);
	lseek(fd, 0, SEEK_SET);
	bytes_read = read(fd, buffer, sizeof(buffer));
	buffer[bytes_read] = '\0';

	snprintf(expected, sizeof(expected), "%s\n", str);
	if (strcmp(buffer, expected) == 0)
	{
		printf("test for \"%s\": "GREEN" PASS\n" RESET, buffer);
		pass_count++;
	}
	else
	{
		printf("Test for \"%s\": "RED" FAIL\n" RESET, buffer);
		printf("Expected \'%s\', but we got "CYAN"%s.\n" RESET, str, buffer);
		fail_count++;
	}
	close(fd);
	//unlink("test_output.txt");
}

int main()
{
	test_ft_putendl_fd("HILLgrid");
	test_ft_putendl_fd("Hey you out there in the cold");
	test_ft_putendl_fd("0102034go24");

	if (fail_count == 0)
		return (0);
	else
	{
		printf(RED"%d out of %d failed\n"RESET, fail_count, pass_count + fail_count);
		return (1);
	}
}
