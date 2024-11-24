/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:07:06 by agaga             #+#    #+#             */
/*   Updated: 2024/11/06 18:21:16 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../util/tester.h"

void test_ft_putnbr_fd(int nbr)
{
    int fd;
    char buffer[256];
    ssize_t bytes_read;
    char expected[256];

    fd = open("test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Error opening file");
        return;
    }
    ft_putnbr_fd(nbr, fd);
    lseek(fd, 0, SEEK_SET);
    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1)
    {
        perror("Error reading file");
        close(fd);
        return;
    }
    buffer[bytes_read] = '\0';

    snprintf(expected, sizeof(expected), "%d", nbr);

    if (strcmp(buffer, expected) == 0)
    {
        printf("test for \"%d\": " GREEN "PASS\n" RESET, nbr);
        pass_count++;
    }
    else
    {
        printf("Test for \"%d\": " RED "FAIL\n" RESET, nbr);
        printf("Expected '%s', but we got " CYAN "%s.\n" RESET, expected, buffer);
        fail_count++;
    }
    close(fd);
    unlink("test_output.txt");
}

int main()
{
	test_ft_putnbr_fd(1202);
	test_ft_putnbr_fd(7410);
	test_ft_putnbr_fd(-959);
	test_ft_putnbr_fd(-2147483648);

	if (fail_count == 0)
		return (0);
	else
	{
		printf(RED"%d out of %d failed"RESET, fail_count, pass_count + fail_count);
		return (1);
	}
}
