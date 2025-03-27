/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plimbu <plimbu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:28:51 by plimbu            #+#    #+#             */
/*   Updated: 2025/03/27 18:28:55 by plimbu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_str(t_srv *s)
{
	ft_printf("%s\n", s->buf);
	free(s->buf);
	s->buf = NULL;
	s->c = 0;
	s->buf_size = 1;
	s->buf_idx = 0;
	s->bit_count = 0;
}

void	store_str(t_srv *s)
{
	char	*new_buf;

	if (s->buf_idx >= s->buf_size - 1)
	{
		s->buf_size *= 2;
		new_buf = (char *)malloc(s->buf_size);
		if (!new_buf)
		{
			free(s->buf);
			exit(ft_printf("Memory allocation failed\n"));
		}
		ft_memcpy(new_buf, s->buf, s->buf_idx);
		free(s->buf);
		s->buf = new_buf;
	}
	s->buf[s->buf_idx++] = s->c;
	if (s->c == '\0')
		print_str(s);
	s->c = 0;
	s->bit_count = 0;
}

void	handle_client_signal(int signum, siginfo_t *siginfo, void *context)
{
	static t_srv	states;

	(void)context;
	if (!states.buf)
	{
		states.buf_size = 1;
		states.buf = (char *)malloc(states.buf_size);
		if (!states.buf)
			exit(ft_printf("Memory allocation failed\n"));
		states.buf_idx = 0;
		states.c = 0;
		states.bit_count = 0;
	}
	if (signum == SIGUSR2)
		states.c |= 1;
	if (++states.bit_count == 8)
		store_str(&states);
	states.c <<= 1;
	if (kill(siginfo->si_pid, SIGUSR1) == -1)
		exit(ft_printf("Error sending signal\n"));
}

int	main(void)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sa.sa_sigaction = &handle_client_signal;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(ft_printf("Error setting up signal handler\n"));
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
