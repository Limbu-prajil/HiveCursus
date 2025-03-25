#include "minitalk.h"

void store_print(t_srv *s)
{
    char *new_buf;
    
    if (s->buf_idx >= s->buf_size - 1)
    {
        s->buf_size *= 2;
        new_buf = (char *)malloc(s->buf_size);
        if (!new_buf)
        {
            free(s->buf);
            exit(ft_printf("Memory allocation failed\n"));
        }
        free(s->buf);
        s->buf = ft_memcpy(new_buf, s->buf, s->buf_idx);
    }
    s->buf[s->buf_idx++] = s->c;
    if (s->c == '\0')
    {
        ft_printf("%s\n", s->buf);
        free(s->buf);
        s->buf = NULL;
        s->buf_size = 1;
        s->buf_idx = 0;
    }
    s->c = 0;
    s->bit_count = 0;
}

void handle_client_signal(int signum, siginfo_t *siginfo, void *context)
{
    static t_srv states;
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
        store_print(&states);
    states.c <<= 1;
    if (kill(siginfo->si_pid, SIGUSR1) == -1)
        exit(ft_printf("Error sending signal\n"));
}

int main(void)
{
    struct sigaction sa;

    ft_bzero(&sa, sizeof(struct sigaction));
    sa.sa_sigaction = &handle_client_signal;
    sa.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
        exit(ft_printf("Error setting up signal handler\n"));
    ft_printf("Server PID: %d\n", getpid());
    while (1)
        pause();
    return (0);
}
