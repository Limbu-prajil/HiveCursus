char *my_strdup(const char *s) {
    size_t len = strlen(s) + 1;        // Calculate length of string including null terminator
    char *dup = malloc(len);           // Allocate memory for the duplicate string
    if (dup)                           // If allocation successful
        my_memcpy(dup, s, len);        // Copy original string to allocated memory
    return dup;                        // Return pointer to duplicated string
}

