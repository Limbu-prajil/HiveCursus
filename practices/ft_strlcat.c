#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t ft_strlcat(char *dst, const char *src, size_t size) {
    size_t dst_len = 0;
    size_t src_len = 0;
    size_t i;

    // Calculate the length of src
    while (src[src_len] != '\0')
        src_len++;

    // Calculate the length of dst (up to size)
    while (dst_len < size && dst[dst_len] != '\0')
        dst_len++;

    // If size is smaller than or equal to dst_len, return size + src_len
    if (size <= dst_len)
        return size + src_len;

    // Append src to dst while ensuring null termination
    i = 0;
    while (src[i] != '\0' && (dst_len + i + 1) < size) {
        dst[dst_len + i] = src[i];
        i++;
    }

    // Null-terminate dst
    dst[dst_len + i] = '\0';

    // Return the total length of dst and src as if size was unlimited
    return dst_len + src_len;
}


int main() {
    char dst[10];        // Destination buffer
    const char *src = "world!";
    size_t size;
    size_t result;

    // Test Case 1: Normal concatenation
    strcpy(dst, "Hello, ");
    size = sizeof(dst);
    result = ft_strlcat(dst, src, size);
    printf("Test 1:\n");
    printf("Resulting string: \"%s\"\n", dst);
    printf("Total length: %zu\n\n", result);

    // Test Case 2: Buffer too small
    strcpy(dst, "Hi");
    size = 5; // Small buffer
    result = ft_strlcat(dst, src, size);
    printf("Test 2:\n");
    printf("Resulting string: \"%s\"\n", dst);
    printf("Total length: %zu\n\n", result);

    // Test Case 3: Zero size
    strcpy(dst, "Test");
    size = 0; // No buffer
    result = ft_strlcat(dst, src, size);
    printf("Test 3:\n");
    printf("Resulting string: \"%s\" (should remain unchanged)\n", dst);
    printf("Total length: %zu\n\n", result);

    return 0;
}

