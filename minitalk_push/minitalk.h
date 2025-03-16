#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft/libft.h"

#define BUFFERSIZE 1048576  // Define a reasonable buffer size

typedef struct s_server
{
    char    buffer[BUFFERSIZE];  // Store received characters
    size_t  index;                // Current position in buffer
    char    character;             // Reconstruct received character
    int     bit_count;             // Track received bits
}   t_server;

#endif

