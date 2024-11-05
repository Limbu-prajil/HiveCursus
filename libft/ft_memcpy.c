void *my_memcpy(void *dest, const void *src, size_t n) {
    unsigned char *d = dest;        // Create unsigned char pointers for byte-wise copy
    const unsigned char *s = src;
    while (n--) {                   // Loop n times
        *d++ = *s++;                // Copy each byte from src to dest
    }
    return dest;                    // Return pointer to destination
}

