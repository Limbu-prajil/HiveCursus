#include "minitalk.h"
#include "libft/libft.h"

void handle_client_signal(int signum, siginfo_t *siginfo, void *context)
{
	static t_srv states = {0, 0, 0, {0}}; // Struct to hold server states
    (void)context;  // Unused parameter

    // If SIGUSR1 is received, set the least significant bit
    if (signum == SIGUSR1)
        states.character |= 1;

    states.bit_count++;  // Increment the bit count

    if (states.bit_count == 8)  // When 8 bits (1 char) are received
    {
        states.buffer[states.buffer_index++] = states.character; // Store character in buffer
        if (states.character == '\0' || states.buffer_index >= BUFFERSIZE - 1) // If end of string or buffer is full
        {
            ft_printf("%s", states.buffer); // Print full message
            states.buffer_index = 0; // Reset buffer for next message
        }
        states.character = 0; // Reset character for next byte
        states.bit_count = 0; // Reset bit count
    }

    states.character <<= 1;  // Shift left for the next bit

    // Acknowledge the client by sending SIGUSR1
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

