#include "minitalk.h"

void handle_client_signal(int signum, siginfo_t *siginfo, void *context)
{
    static char *buffer = NULL; // Dynamically allocated buffer
    static int buffer_size = 1; // Start with a small buffer
    static int buffer_index = 0;
    static char character = 0;
    static int bit_count = 0;
    char *new_buffer;
    (void)context;

    if (!buffer)
        buffer = (char *)malloc(buffer_size);
    if (!buffer)
        exit(ft_printf("Memory allocation failed\n"));
    // Set the bit if SIGUSR2 is received
    if (signum == SIGUSR2)
        character |= 1;

    bit_count++;
    if (bit_count == 8)  // If a full character is received
    {
        // Resize buffer if needed
        if (buffer_index >= buffer_size - 1) // Leave space for '\0'
        {
            buffer_size *= 2;
            new_buffer = (char *)malloc(buffer_size);
            if (!new_buffer)
            {
            	free(buffer);
                exit(ft_printf("Memory allocation failed\n"));
            }
            ft_memcpy(new_buffer, buffer, buffer_index); // Copy old data
            free(buffer);
            buffer = new_buffer;
        }
        buffer[buffer_index++] = character; // Store the character

        if (character == '\0') // If end of string is received
        {
            ft_printf("%s\n", buffer); // Print the whole message
            free(buffer); // Free memory
            buffer = NULL; // Reset for next message
            buffer_size = 1;
            buffer_index = 0;
        }

        character = 0; // Reset for next character
        bit_count = 0;
    }

    character <<= 1; // Shift for the next bit
    // Acknowledge the client
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

