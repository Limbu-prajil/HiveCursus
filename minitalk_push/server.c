#include "minitalk.h"
/*
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
    if (signum == SIGUSR2) // Set the bit if SIGUSR2 is received
        character |= 1;
    bit_count++;
    if (bit_count == 8)  // If a full character is received
    {
        if (buffer_index >= buffer_size - 1) // Resize buffer if needed. Leave space for '\0'
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
    if (kill(siginfo->si_pid, SIGUSR1) == -1) // Acknowledge the client
        exit(ft_printf("Error sending signal\n"));
} */

void store_char(char **buffer, int *buf_size, int *buf_idx, char c)
{
    char *new_buf;
    if (*buf_idx >= *buf_size - 1)
    {
        *buf_size *= 2;
        new_buf = (char *)malloc(*buf_size);
        if (!new_buf)
            exit(ft_printf("Memory allocation failed\n"));
        ft_memcpy(new_buf, *buffer, *buf_idx);
        free(*buffer);
        *buffer = new_buf;
    }
    (*buffer)[(*buf_idx)++] = c;
}

void handle_client_signal(int signum, siginfo_t *siginfo, void *context)
{
    static t_srv states = {NULL, 0, 1, 0, 0};
    (void)context;

    if (!states.buf && !(states.buf = (char *)malloc(states.buf_size)))
        exit(ft_printf("Memory allocation failed\n"));
    if (signum == SIGUSR1)
        states.c |= 1;
    if (++states.bit_count == 8)
    {
        store_char(&states.buf, &states.buf_size, &states.buf_idx, states.c);
        if (states.c == '\0')
        {
            ft_printf("%s\n", states.buf);
            free(states.buf);
            states.buf = NULL;
            states.buf_size = 1;
            states.buf_idx = 0;
        }
        states.c = 0;
        states.bit_count = 0;
    }
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

