void	*my_memset(void *s, int c, size_t n) {
    unsigned char *p = s;          // Create an unsigned char pointer to traverse the memory block
    while (n--) {                   // Loop n times
        *p++ = (unsigned char)c;    // Assign c to each byte in memory and move to the next byte
    }
    return s;                       // Return the original pointer
}

