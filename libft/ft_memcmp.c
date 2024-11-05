int my_memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *p1 = s1;   // Create unsigned char pointers for byte comparison
    const unsigned char *p2 = s2;
    while (n--) {                   // Loop n times
        if (*p1 != *p2)             // Check if current bytes differ
            return *p1 - *p2;       // Return difference between mismatching bytes
        p1++, p2++;                 // Move to next byte
    }
    return 0;                       // Return 0 if all bytes match
}

