#include "minitalk.h"
#include "libft/libft.h"
/*
t_server g_server = {{0}, 0, 0, 0, 0};  // Global struct to hold server state

void handle_client_signal(int signum, siginfo_t *siginfo, void *context)
{
    (void)context;

    // If a new client connects, reset server state
    if (g_server.client_pid != siginfo->si_pid)
    {
        g_server.client_pid = siginfo->si_pid;
        g_server.index = 0;
    }

    // Shift character left and set bit if SIGUSR1 is received
    g_server.character = (g_server.character << 1) | (signum == SIGUSR1);
    g_server.bit_count++;

    // Once 8 bits are received, store the character
    if (g_server.bit_count == 8)
    {
        if (g_server.index < BUFFER_SIZE - 1)
            g_server.buffer[g_server.index++] = g_server.character;

        if (g_server.character == '\0')  // When null terminator is received, print and reset buffer
        {
            ft_printf("%s\n", g_server.buffer);
            ft_bzero(g_server.buffer, BUFFER_SIZE);
            g_server.index = 0;
        }
        g_server.bit_count = 0;
        g_server.character = 0;
    }

    // Send acknowledgment signal to client
    if (kill(siginfo->si_pid, SIGUSR1) == -1)
        exit(ft_printf("Error sending signal\n"));
}
*/

void handle_client_signal(int signum, siginfo_t *siginfo, void *context)
{
    static char character = 0;  // Holds the current character being built
    static int bit_count = 0;   // Tracks number of received bits
    static char buffer[BUFFERSIZE]; // Buffer to store the received string
    static int buffer_index = 0; // Index to track buffer position
    (void)context;  // Unused parameter

    // If SIGUSR1 is received, set the least significant bit
    if (signum == SIGUSR1)
        character |= 1;

    bit_count++;  // Increment the bit count

    if (bit_count == 8)  // When 8 bits (1 char) are received
    {
        buffer[buffer_index++] = character; // Store character in buffer
        if (character == '\0' || buffer_index >= BUFFERSIZE - 1) // If end of string or buffer is full
        {
            ft_printf("%s\n", buffer); // Print full message
            buffer_index = 0; // Reset buffer for next message
        }
        character = 0; // Reset character for next byte
        bit_count = 0; // Reset bit count
    }

    character <<= 1;  // Shift left for the next bit

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

