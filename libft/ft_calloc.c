void *my_calloc(size_t nmemb, size_t size) {
    size_t total_size = nmemb * size; // Calculate total bytes needed
    void *ptr = malloc(total_size);   // Allocate the required memory
    if (ptr)                          // If allocation successful
        my_memset(ptr, 0, total_size); // Initialize memory to 0
    return ptr;                       // Return pointer to allocated memory
}

