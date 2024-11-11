#include "libft.h"

void	test_ft_calloc()
{
    // Basic Valid Case
    int *ptr1 = my_calloc(5, sizeof(int));
    if (ptr1 && memcmp(ptr1, (int[5]){0}, 5 * sizeof(int)) == 0) 
        printf("Basic valid case passed.\n");
    else 
        printf("Basic valid case failed.\n");
    free(ptr1);

    // Zero Elements or Zero Size
    int *ptr2 = my_calloc(0, sizeof(int));
    if (ptr2 == NULL) printf("Zero elements case passed.\n");

    int *ptr3 = my_calloc(5, 0);
    if (ptr3 == NULL) printf("Zero size case passed.\n");

    // Maximum Memory Request (Overflow)
    int *ptr4 = my_calloc(SIZE_MAX, 2);
    if (ptr4 == NULL) printf("Overflow case passed.\n");

    // Boundary Condition
    int *ptr5 = my_calloc(SIZE_MAX, 1);
    if (ptr5) printf("Boundary condition passed (if not NULL).\n");
    free(ptr5);

    // Minimum Non-zero Allocation
    char *ptr6 = my_calloc(1, 1);
    if (ptr6 && *ptr6 == 0) printf("Minimum allocation passed.\n");
    free(ptr6);

    // Large Allocation (Stress Test)
    int *ptr7 = my_calloc(1000000, sizeof(int));
    if (ptr7) printf("Large allocation passed.\n");
    free(ptr7);
    
    // Memory Content Check (Zero Initialization)
    int *ptr8 = my_calloc(10, sizeof(int));
    if (ptr8 && memcmp(ptr8, (int[10]){0}, 10 * sizeof(int)) == 0)
        printf("Zero initialization passed.\n");
    else 
        printf("Zero initialization failed.\n");
    free(ptr8);
}

int main() {
    test_my_calloc();
    return 0;
}
