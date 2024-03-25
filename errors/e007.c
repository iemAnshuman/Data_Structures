#include <stdio.h>

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    // Attempting to access an element outside the array's bounds
    int value = numbers[10]; // Out of bounds access

    printf("Value: %d\n", value);
    return 0;
}
