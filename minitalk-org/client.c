#include "minitalk.h"
#include "libft/libft.h"

// Global variable initially set to 0, indicating that no bit has been received
int g_bit_received;

void send_bit(int pid, int bit)
{
    int signal;
    // Determine the signal based on the bit value
    if (bit == 1)
        signal = SIGUSR1;
    else
        signal = SIGUSR2;
    // Send the signal to the server (server's PID)
    if (kill(pid, signal) == -1)
        exit(ft_printf("Error sending signal\n"));
}

void send_char(int pid, unsigned char c)
{
    int i = 7;
    while (i >= 0) // Iterate through each bit of the character
    {
        g_bit_received = 0; // Reset the flag indicating bit reception
        send_bit(pid, (c >> i) & 1); // Send the current bit
        while (!g_bit_received)
            pause(); // Wait for acknowledgment of bit reception
    	i--;
    }
}

void send_string(int pid, const char *str)
{
    while (*str)
        send_char(pid, *str++);
    send_char(pid, '\0'); // Send a null character to mark the end of the string
}

void handle_server_signal(int signum)
{
    if (signum == SIGUSR1)
        g_bit_received = 1; // Set the flag to indicate bit reception
}

int main(int argc, char **argv)
{
    struct sigaction sig;
    int server_pid;

    // Check if the correct number of command-line arguments is provided
    if (argc != 3)
        exit(ft_printf("Correct usage: ./client [server's PID] [string]\n"));
    // Convert the server's PID from string to integer
    server_pid = ft_atoi(argv[1]);    
    // Check if the provided PID is valid
    if (kill(server_pid, 0) == -1 || server_pid == 0)
        exit(ft_printf("Invalid PID: %s\n", argv[1]));
    // Initialize the signal handling structure
    ft_bzero(&sig, sizeof(struct sigaction));
    sig.sa_handler = &handle_server_signal;
    // Set up a signal handler for SIGUSR1 signals
    if (sigaction(SIGUSR1, &sig, NULL) == -1)
        exit(ft_printf("Error setting up signal handler\n"));
    // Send the input string to the server as a series of bits
    send_string(server_pid, argv[2]);
    //send_string(server_pid, "\n"); // Send a newline character to mark the end of the string
    // Print a message indicating that the string has been sent
    ft_printf("String sent\n");

    return (0);
}
