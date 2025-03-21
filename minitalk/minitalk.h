#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft/libft.h"

#define BUFFERSIZE 1024  // Define a reasonable buffer size

typedef struct s_server
{
    char    buffer[BUFFERSIZE];  // Store received characters
    size_t  index;                // Current position in buffer
    char    character;             // Reconstruct received character
    int     bit_count;             // Track received bits
    pid_t   client_pid;            // Track current client's PID
}   t_server;

#endif

