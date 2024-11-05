void *my_memchr(const void *s, int c, size_t n) {
    const unsigned char *p = s;     // Create an unsigned char pointer for byte-level access
    while (n--) {                   // Loop n times
        if (*p == (unsigned char)c) // Check if the current byte matches c
            return (void *)p;       // If found, return pointer to the matching byte
        p++;                        // Move to the next byte
    }
    return NULL;                    // If not found, return NULL
}

