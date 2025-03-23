#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft/libft.h"

#define BUFFERSIZE 1024  // Define a reasonable buffer size

typedef struct s_srv
{
    int	   buffer_index;           // Current position in buffer. Index to track buffer position
    char    character;             // Reconstruct received character. Holds current character being built
    int     bit_count;             // Tracks number of received bits. Reinitialise again for next tracking
    char    buffer[BUFFERSIZE];    // Store received characters. Buffer to store recieved string
}   t_srv;

#endif
