#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * 1 << (7 - bit_count)
 * shifts the one to the left 7 - bit_count times
 * ex: 1 << 4 -> 10000
 * (...)
 * evaluates to a 1 if we have a value or 0 if none
 * ex: (0100) -> 1 and (0000) -> 0
 * c |= ...
 * is a bitwise or, if any of the bits is 1, stays 1
 * othwise set to 0
 * so we start from the right and set each bit we need to 1
*/
static void	handle_signal(int signo, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bit_count;
	pid_t					client_pid;

	client_pid = info->si_pid;
	if (signo == SIGUSR1)
	{
		bit_count++;
	}
	if (signo == SIGUSR2)
	{
		c |= (1 << (7 - bit_count));
		bit_count++;
	}
	if (bit_count == 8)
	{
		ft_printf("%c", c);
		bit_count = 0;
		c = 0;
	}
	kill(client_pid, SIGUSR1);
	(void)context;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig_action;

	pid = getpid();
	if (!pid)
	{
		ft_printf("there was an error getting pid");
		exit(EXIT_FAILURE);
	}
	sig_action.sa_flags = SA_SIGINFO;
	sig_action.sa_sigaction = handle_signal;
	ft_printf("%i\n", pid);
	sigaction(SIGUSR1, &sig_action, NULL);
	sigaction(SIGUSR2, &sig_action, NULL);
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
