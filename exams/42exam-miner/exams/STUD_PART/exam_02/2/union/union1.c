#include <unistd.h>

int main(int ac, char **av)
{
    char asc[256] = {0};  // Initialize all elements to 0

    if (ac != 3)
    {
        write(1, "check\n", 6);
        return 1;  // Exit if the number of arguments is not 2
    }

    for (int i = 1; i < ac; i++)  // Start from 1 to skip the program name
    {
        for (int j = 0; av[i][j] != '\0'; j++)  // Loop until the end of the string
        {
            int c = av[i][j];  // Ensure the character is within 0-255
            if (asc[c] == 0)  // Check if the character has not been printed yet
            {
                asc[c] = 1;  // Mark the character as printed
                write(1, &c, 1);  // Print the character
            }
        }
    }

    write(1, "\n", 1);  // Print a newline at the end
    return 0;  // Indicate successful execution
}
