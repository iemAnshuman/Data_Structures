#include <stdio.h>

// Function declaration
int multiplyNumbers(int a, int b);

int main() {
    int result;

    // Attempt to use the function
    result = multiplyNumbers(5, 4);

    printf("Result: %d\n", result);
    return 0;
}

// The definition for multiplyNumbers is missing, leading to a linker error.
