#include "../libft/libft.h"

void print_test_result(const char *description, int result) {
    printf("%s: %s\n", description, result ? "PASS" : "FAIL");
}

void test_ft_memcpy() {
    char src1[] = "Copy this text";
    char dest1[20];
    char dest2[20] = "Unchanged buffer";
    char src3[] = "";
    char dest3[20] = "Non-empty buffer";

    // Standard copy
    ft_memcpy(dest1, src1, strlen(src1) + 1);  // +1 to include null terminator
    print_test_result("Standard copy", strcmp(dest1, src1) == 0);

    // Zero-length copy (should not change destination)
    ft_memcpy(dest2, src1, 0);
    print_test_result("Zero-length copy", strcmp(dest2, "Unchanged buffer") == 0);
    
    // Empty src copy ( 0 byte from src is copied )
    ft_memcpy(dest3, src3, 1);
    print_test_result("", strcmp(dest3, "Non-empty buffer") == 0);

    // Exact size copy
    char src4[] = "Exact";
    char dest4[6];
    ft_memcpy(dest4, src4, strlen(src4) + 1);
    print_test_result("Exact size copy", strcmp(dest4, src4) == 0);

    // Boundary condition - Copying to the start of destination buffer
    char dest5[20] = "Test boundary copy";
    ft_memcpy(dest5, src1, 4);
    print_test_result("Boundary condition - Copying to start", strncmp(dest5, src1, 4) == 0);

    // Large data copy
    char large_src[1000];
    char large_dest[1000];
    memset(large_src, 'A', 1000);
    large_src[999] = '\0';
    ft_memcpy(large_dest, large_src, 1000);
    print_test_result("Large data copy", memcmp(large_dest, large_src, 1000) == 0);

    // Non-printable and null bytes
    char non_printable_src[] = {0, 1, 2, 3, 4, 5, 0, 'a', 'b', 'c'};
    char non_printable_dest[10];
    ft_memcpy(non_printable_dest, non_printable_src, 10);
    print_test_result("Non-printable and null bytes", memcmp(non_printable_dest, non_printable_src, 10) == 0);

    // Check for no overlap handling (ft_memcpy assumes non-overlapping memory regions)
    char src_overlap[] = "Overlap source";
    ft_memcpy(src_overlap + 3, src_overlap, strlen(src_overlap) + 1);
    print_test_result("No overlap handling (memcmp)", memcmp(src_overlap + 3, src_overlap, strlen(src_overlap)) != 0);
}

int main() {
    printf("Testing ft_memcpy...\n");
    test_ft_memcpy();
    return 0;
}

