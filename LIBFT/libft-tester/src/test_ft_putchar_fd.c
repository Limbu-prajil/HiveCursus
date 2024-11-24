/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:36:05 by agaga             #+#    #+#             */
/*   Updated: 2024/11/11 16:39:51 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/tester.h"
#include "../../libft/libft.h"

void test_ft_putchar_fd()
{
    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Failed to open file for writing");
        return;
    }

    char test_char = 'A';
    ft_putchar_fd(test_char, fd);
    close(fd);

    fd = open("test_output.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Failed to open file for reading");
        return;
    }
    
	char read_char;
    if (read(fd, &read_char, 1) != 1)
    {
        perror("Failed to read character from file");
        close(fd);
        return;
    }

    if (read_char == test_char)
    {
        printf(GREEN"Test Passed: Character written and read correctly\n"RESET);
		pass_count++;
    }
    else
    {
        printf("Test Failed: Character mismatch\n");
		fail_count++;
    }
    close(fd);
    remove("test_output.txt");
}

int main()
{
    test_ft_putchar_fd();
    if (fail_count == 0)
		return 0;
	else
	{
		printf(RED"Test Failed\n"RESET);
		return 1;
	}
}
