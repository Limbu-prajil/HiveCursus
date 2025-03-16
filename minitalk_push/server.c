#include "minitalk.h"
#include "libft/libft.h"
/*
t_server g_server = {{0}, 0, 0, 0, 0};  // Global struct to hold server state

void handle_client_signal(int signum, siginfo_t *siginfo, void *context)
{
    (void)context;

    // Shift character left and set bit if SIGUSR1 is received
    g_server.character = (g_server.character << 1) | (signum == SIGUSR1);
    g_server.bit_count++;

    // Once 8 bits are received, store the character
    if (g_server.bit_count == 8)
    {
        if (g_server.index < BUFFERSIZE - 1)
            g_server.buffer[g_server.index++] = g_server.character;

        if (g_server.character == '\0')  // When null terminator is received, print and reset buffer
        {
            ft_printf("%s\n", g_server.buffer);
            ft_bzero(g_server.buffer, BUFFERSIZE);
            g_server.index = 0;
        }
        g_server.bit_count = 0;
        g_server.character = 0;
    }
    character <<=1;
    // Send acknowledgment signal to client
    if (kill(siginfo->si_pid, SIGUSR1) == -1)
        exit(ft_printf("Error sending signal\n"));
}
*/

void handle_client_signal(int signum, siginfo_t *siginfo, void *context)
{
    static char character = 0;
    static int bit_count = 0;
    static char buffer[BUFFERSIZE];
    static int buffer_index = 0;
    (void)context;

    if (signum == SIGUSR1)
        character |= 1;
    bit_count++;
    if (bit_count == 8)
    {
        buffer[buffer_index++] = character;
        if (character == '\0' || buffer_index >= BUFFERSIZE - 1)
        {
            ft_printf("%s\n", buffer);
            ft_bzero(buffer, BUFFER_SIZE);
            buffer_index = 0;
        }
        character = 0;
        bit_count = 0;
    }
    character <<= 1;
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

