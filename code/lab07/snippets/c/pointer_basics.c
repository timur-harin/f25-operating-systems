#include <stdio.h>
#include <stdlib.h>

void demonstrate_pointers(void) {
    int x = 42;
    int *ptr = &x;
    
    printf("=== Pointer Basics ===\n\n");
    
    printf("Variable x:\n");
    printf("  Value:   %d\n", x);
    printf("  Address: %p\n\n", (void *)&x);
    
    printf("Pointer ptr:\n");
    printf("  Points to:  %p\n", (void *)ptr);
    printf("  Value at *ptr: %d\n", *ptr);
    printf("  Address of ptr itself: %p\n\n", (void *)&ptr);
    
    // Modify through pointer
    *ptr = 100;
    printf("After *ptr = 100:\n");
    printf("  x = %d\n", x);
    printf("  *ptr = %d\n\n", *ptr);
    
    // Pointer arithmetic
    int array[5] = {10, 20, 30, 40, 50};
    int *arr_ptr = array;
    
    printf("=== Pointer Arithmetic ===\n\n");
    printf("Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
    
    printf("Accessing via pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("  *(arr_ptr + %d) = %d  (address: %p)\n", 
               i, *(arr_ptr + i), (void *)(arr_ptr + i));
    }
    
    // Pointer to pointer
    printf("\n=== Pointer to Pointer ===\n\n");
    int **ptr_ptr = &ptr;
    printf("  ptr points to x at: %p\n", (void *)ptr);
    printf("  ptr_ptr points to ptr at: %p\n", (void *)ptr_ptr);
    printf("  **ptr_ptr (value of x): %d\n", **ptr_ptr);
}

void swap_by_reference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    printf("Pointer Demonstration\n");
    printf("=====================\n\n");
    
    demonstrate_pointers();
    
    printf("\n=== Pass by Reference ===\n\n");
    int num1 = 5, num2 = 10;
    printf("Before swap: num1=%d, num2=%d\n", num1, num2);
    swap_by_reference(&num1, &num2);
    printf("After swap:  num1=%d, num2=%d\n", num1, num2);
    
    printf("\nKey Takeaways:\n");
    printf("  - Pointers store memory addresses\n");
    printf("  - & operator gets address of variable\n");
    printf("  - * operator dereferences (accesses value at address)\n");
    printf("  - Pointer arithmetic: ptr+1 moves by sizeof(type) bytes\n");
    printf("  - Pass by reference allows function to modify variables\n");
    
    return 0;
}

