#include <stdio.h>
#include <stdlib.h>

// to calculate GCD of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Function to find the minimum operations needed
int minOperations(int arr[], int n, int k) {
    int total = 0;
    
    int current = arr[0];
    for (int i = 1; i < n; i++) {
        current = gcd(current, arr[i]);
    }
    
    // If the GCD is already divisible by K, no operations are needed
    if (current % k == 0) {
        return 0;
    }
    
    // Adjust each box to make the GCD divisible by K
    for (int i = 0; i < n; i++) {
        int ops = 0;
        while (gcd(current, arr[i] + ops) % k != 0 && gcd(current, abs(arr[i] - ops)) % k != 0) {
            ops++;
        }
        
        // Choose the minimal adjustment
        total += ops;
    }
    
    return total;
}

int main() {
    int n, k;
    printf("Enter the number of boxes (N) and the divisor (K): ");
    scanf("%d %d", &n, &k);
    
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter the number of balls in each box:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int result = minOperations(arr, n, k);
    printf("Minimum operations required: %d\n", result);
    
    free(arr);
    return 0;
}
