#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements in the array A: ");
    scanf("%d", &n);
    
    int A[n];
    printf("Enter the elements of the array A:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    int sum = 0, start = 0;
    int found = 0; // Flag to check if at least one sub-array with non-zero sum exists
    
    printf("\n");
    for(int i = 0; i < n; i++) {
        sum += A[i];
        // If sum is non-zero and it is the last element or the sum becomes zero in the next step
        if(sum != 0 && (i == n-1 || sum + A[i+1] == 0)) {
            if(!found) {
                printf("YES\n");
                found = 1; // Found at least one valid sub-array
            }
            printf("%d %d\n", start + 1, i + 1); // 1-based index
            sum = 0; // Reset sum for the next sub-array
            start = i + 1; // Update start for the next sub-array
        }
    }
    
    if(!found) {
        printf("NO\n"); // Couldn't split the array as per conditions
    }
    
    return 0;
}
