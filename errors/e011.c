#include <stdio.h>

int main() {
    int *ptr = NULL; // Initialize a pointer to NULL
    printf("%d\n", *ptr); // Attempt to dereference the NULL pointer
    return 0;
}
