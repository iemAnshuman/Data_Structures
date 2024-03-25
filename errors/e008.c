#include <stdio.h>

// Function declared to return an integer
int addTwoNumbers(int a, int b) {
    int sum = a + b;
    // Missing return statement
}

int main() {
    int result = addTwoNumbers(5, 3);
    printf("Result: %d\n", result);
    return 0;
}
