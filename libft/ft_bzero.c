void my_bzero(void *s, size_t n) {
    unsigned char *p = s;          // Create a byte-level pointer to traverse memory
    while (n--) {                  // Loop n times, where n is the number of bytes to clear
        *p++ = 0;                  // Set each byte to 0, then move to the next byte
    }
}

