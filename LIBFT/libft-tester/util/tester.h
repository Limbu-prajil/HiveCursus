#ifndef TESTER_H
# define TESTER_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <stddef.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h> 
# include <unistd.h>
# include <assert.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BOLD "\033[1m"
# define RESET "\033[0m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"


int pass_count = 0; 
int fail_count = 0;
int iTest = 1;

#endif
