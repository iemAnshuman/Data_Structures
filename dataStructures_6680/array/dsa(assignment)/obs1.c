#include <stdio.h>
#include <stdlib.h>

// Function to attempt deleting an element - will cause a compilation error due to incorrect access
void attemptToDeleteElementIncorrectly(int **arr, int size, int position) {
    for (int i = position; i < size - 1; i++) {
        // Incorrect line: Trying to use arr as if it were a single pointer to int
        // This will cause a compilation error because arr is a pointer to a pointer to int
        arr[i] = arr[i + 1];
    }
}

int main() {
    int *array;
    int size = 5; // Example size

    // Dynamically allocate memory for the array
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize array with example values
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }

    // Attempt to delete an element incorrectly
    attemptToDeleteElementIncorrectly(&array, size, 2); // This line is fine, but the function itself contains an error

    // Normally, you'd do something with the array here

    // Free the allocated memory
    free(array);

    return 0;
}
