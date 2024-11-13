#include "../libft/libft.h"

void print_test_result(const char *description, int result) {
    printf("%s: %s\n", description, result ? "PASS" : "FAIL");
}

void test_ft_memmove() {
    char buffer[] = "Overlap test case";
    char src1[] = "Hello, World!";
    char dest1[20];
    char dest2[20] = "Unchanged buffer";
    char src3[] = "";
    char dest3[20] = "Non-empty buffer";
    
    // Overlapping regions (source before destination)
    ft_memmove(buffer + 7, buffer, 6);
    print_test_result("Overlapping regions (src before dest)", strcmp(buffer, "OverlapOverlap") == 0);

    // Reset buffer
    strcpy(buffer, "Overlap test case");

    // Overlapping regions (destination before source)
    ft_memmove(buffer, buffer + 7, 8);
    print_test_result("Overlapping regions (dest before src)", strcmp(buffer, "test case") == 0);

    // Zero-length move
    char src[] = "Example";
    char dest[20] = "Destination";
    ft_memmove(dest, src, 0);
    print_test_result("Zero-length move", strcmp(dest, "Destination") == 0);
    
    // Empty src copy ( 0 byte from src is copied )
    ft_memmove(dest3, src3, 1);
    print_test_result("", strcmp(dest3, "Non-empty buffer") == 0);
    
    printf("\n");
    // Standard copy (non-overlapping)
    ft_memmove(dest1, src1, strlen(src1) + 1);  // +1 to include null terminator
    print_test_result("Standard copy (non-overlapping)", strcmp(dest1, src1) == 0);

    // Zero-length copy (should not change destination)
    ft_memmove(dest2, src1, 0);
    print_test_result("Zero-length copy", strcmp(dest2, "Unchanged buffer") == 0);

    // Exact size copy
    char src4[] = "Exact size";
    char dest4[11];
    ft_memmove(dest4, src4, strlen(src4) + 1);
    print_test_result("Exact size copy", strcmp(dest4, src4) == 0);

    // Overlap: Source before destination (forward overlap)
    char overlap_src[] = "Overlapping";
    ft_memmove(overlap_src + 4, overlap_src, 7);  // "Overlapping" becomes "OverOver"
    print_test_result("Overlap (source before destination)", strcmp(overlap_src, "OverOvering") == 0);

    // Overlap: Destination before source (backward overlap)
    char overlap_dest[] = "Overlapping";
    ft_memmove(overlap_dest, overlap_dest + 4, 7);  // "Overlapping" becomes "appinging"
    print_test_result("Overlap (destination before source)", strcmp(overlap_dest, "appinging") == 0);

    // Boundary condition - Copying to the start of destination buffer
    char dest5[20] = "Test boundary copy";
    ft_memmove(dest5, src1, 4);
    print_test_result("Boundary condition - Copying to start", strncmp(dest5, src1, 4) == 0);

    // Non-printable and null bytes
    char non_printable_src[] = {0, 1, 2, 3, 4, 5, 0, 'a', 'b', 'c'};
    char non_printable_dest[10];
    ft_memmove(non_printable_dest, non_printable_src, 10);
    print_test_result("Non-printable and null bytes", memcmp(non_printable_dest, non_printable_src, 10) == 0);
}

int main() {
    printf("\nTesting ft_memmove...\n");
    test_ft_memmove();
    return 0;
}

