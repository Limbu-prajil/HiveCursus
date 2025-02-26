#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

volatile int	g_ack = 0;

static void	get_ack(int signo)
{
	if (signo == SIGUSR1)
		g_ack = 1;
}

/*
 * 1 << index_char
 * shifts the one index_char to the left
 * ex: 1 << 4 -> 10000
 * c & (...)
 * if one is present in both we keep it, otherwise 0
 * ex: 0101 & 0100 -> 0100
 * (...)
 * evaluates to a 1 if we have a value or 0 if none
 * ex: (0100) -> 1 and (0000) -> 0
 * so we get each bit starting from the left for c
*/
static void	send_char(pid_t pid, unsigned char c)
{
	size_t	index_char;
	int		bit;

	index_char = 8;
	while (index_char--)
	{
		bit = (c & (1 << index_char));
		if (!bit)
			kill(pid, SIGUSR1);
		if (bit)
			kill(pid, SIGUSR2);
		while (!g_ack)
			pause();
		g_ack = 0;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	size_t	index;

	if (argc != 3)
	{
		ft_printf("usage: ./client <server_pid> <message_string>\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("%i is a bad pid\n", pid);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, &get_ack);
	index = 0;
	while (argv[2][index])
	{
		send_char(pid, argv[2][index]);
		index++;
	}
	send_char(pid, '\n');
	return (EXIT_SUCCESS);
}
