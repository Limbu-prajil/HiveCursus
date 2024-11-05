void *my_memmove(void *dest, const void *src, size_t n) {
    unsigned char *d = dest;
    const unsigned char *s = src;
    if (d < s) {                    // Check if destination is before source
        while (n--)                 // Copy forward if no overlap
            *d++ = *s++;
    } else {                        // If destination overlaps source, copy backwards
        d += n;
        s += n;
        while (n--)
            *--d = *--s;
    }
    return dest;                    // Return pointer to destination
}

