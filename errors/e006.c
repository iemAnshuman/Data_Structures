 #include <stdio.h>

int main() {
    double numerator = 10.0;
    double denominator = 0.0;
    double result;

    // This division will cause a runtime error: division by zero.
    result = numerator / denominator;

    printf("Result: %f\n", result);
    return 0;
}
