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
/*
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
            ft_bzero(buffer, BUFFERSIZE);
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
*/

void handle_client_signal(int signum, siginfo_t *siginfo, void *context)
{
    static char *buffer = NULL; // Dynamically allocated buffer
    static int buffer_size = 1; // Start with a small buffer
    static int buffer_index = 0;
    static char character = 0;
    static int bit_count = 0;
    char *new_buffer;
    (void)context;

    // Allocate memory if it's the first character
    if (!buffer)
        buffer = (char *)malloc(buffer_size);

    if (!buffer)
        exit(ft_printf("Memory allocation failed\n"));

    // Set the bit if SIGUSR1 is received
    if (signum == SIGUSR1)
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
                exit(ft_printf("Memory allocation failed\n"));
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

