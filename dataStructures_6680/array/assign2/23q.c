#include <stdio.h>
#include <limits.h> // For INT_MAX

// Function to find the minimum sum of a pair in the array
int min_pair(int arr[], int n) {
    if(n < 2) {
        printf("Invalid input. Array needs at least two elements.\n");
        return -1; // Return an error code
    }

    // Initialize minimum values to maximum possible integer value
    int fm = INT_MAX, sm = INT_MAX;

    // Loop through the array to find the two smallest elements
    for (int i = 0; i < n; i++) {
        if (arr[i] < fm) {
            sm = fm;
            fm = arr[i];
        } else if (arr[i] < sm && arr[i] != fm) {
            sm = arr[i];
        }
    }
    
    // Return the sum of the two smallest elements
    return fm + sm;
}

int main() {
    int n;

    // Input number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find and print the minimum sum of the pair
    int minSum = min_pair(arr, n);
    printf("The minimum sum of any pair is: %d\n", minSum);

    return 0;
}
