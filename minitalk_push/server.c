#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

// The server needs to reconstruct the binary data sent by the client.
void handle_client_signal(int signum, siginfo_t *siginfo, void *context)
{
    static char character;  // Holds the received character
    static int bit_count;   // Counts the number of bits received
    (void)context;  // Unused parameter

    // Check if the signal received is SIGUSR1
    if (signum == SIGUSR1)
        character = character | 1;  // Set the least significant bit of the character
    bit_count++;  // Increment the bit count

    // Check if 8 bits have been received
    if (bit_count == 8)
    {
        // Write the received character to the standard output
        write(1, &character, 1);
        bit_count = 0;     // Reset the bit count
        character = 0;     // Reset the character
    }
    character = character << 1;  // Shift the character to the left

    // Send a SIGUSR1 signal back to the client to acknowledge each bit received
    if (kill(siginfo->si_pid, SIGUSR1) == -1)
        exit(ft_printf("Error sending signal\n"));
}

int main(void)
{
    struct sigaction sa;

    // Initialize sa structure with zeros
    ft_bzero(&sa, sizeof(struct sigaction));

    // Set the signal handler function
    sa.sa_sigaction = &handle_client_signal;
    sa.sa_flags = SA_SIGINFO;

    // Set up signal handlers for SIGUSR1 and SIGUSR2
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
        exit(ft_printf("Error setting up signal handler\n"));

    // Print the server's process ID
    ft_printf("Server PID: %d\n", getpid());

    // Infinite loop to wait for signals
    while (1)
        pause();

    return (0);
}
