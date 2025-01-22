#include <stdio.h>
#include <stdlib.h>

// Define a structure to store allocation information
typedef struct Allocation {
    void *ptr;
    struct Allocation *next;
} Allocation;

static Allocation *allocations = NULL;

// Function to allocate memory and keep track of it
void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Add the allocation to the linked list
    Allocation *new_alloc = (Allocation *)malloc(sizeof(Allocation));
    if (!new_alloc) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_alloc->ptr = ptr;
    new_alloc->next = allocations;
    allocations = new_alloc;

    return ptr;
}

// Function to free all tracked allocations
void free_all() {
    Allocation *current = allocations;
    while (current) {
        Allocation *next = current->next;
        free(current->ptr);
        free(current);
        current = next;
    }
    allocations = NULL;
}

int main() {
    // Example usage
    int *arr = (int *)my_malloc(10 * sizeof(int));
    char *str = (char *)my_malloc(50 * sizeof(char));

    // Use the allocated memory
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    snprintf(str, 50, "Hello, World!");

    printf("Array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nString: %s\n", str);

    // Free all allocations
    free_all();

    return 0;
}